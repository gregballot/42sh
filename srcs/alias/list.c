/*
** list.c for  in /home/ballot_g/rendu/alias
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 18 11:41:07 2014 Gregoire Ballot
** Last update Sun May 25 20:21:14 2014 TAWFIK
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alias.h"
#include "basic_funct.h"

void		my_freelist(t_alias *list)
{
  t_alias	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->cmd);
      free(tmp->alias);
      free(tmp);
    }
}

void		my_freehisto(t_alias_hist *list)
{
  t_alias_hist	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->history);
      free(tmp);
    }
}

void		my_showlist(t_alias *list)
{
  int		i;

  while (list != NULL)
    {
      i = -1;
      write(1, list->alias, my_strlen(list->alias));
      write(1, "=\"", 2);
      while (list->cmd[++i] != '\0')
      	if (list->cmd[i] != '^')
      	  write(1, &(list->cmd[i]), 1);
      	else
      	  write(1, " ", 1);
      write(1, "\"\n", 2);
      list = list->next;
    }
}

int		push_list(t_alias **list, char **alias)
{
  t_alias	*elem;

  if ((elem = malloc(sizeof(t_alias))) == NULL)
    return (-1);
  elem->alias = my_strdup(alias[1]);
  elem->cmd = my_strdup(alias[2]);
  elem->next = (*list);
  (*list) = elem;
  free_tab(alias);
  return (0);
}

int		push_hist(t_alias_hist **list,
			  char *alias, t_alias *l_alias)
{
  t_alias_hist	*elem;
  t_alias_hist	*tmp;

  (void)l_alias;
  tmp = *list;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->history, alias) == 0)
	return (-2);
      tmp = tmp->next;
    }
  if ((elem = malloc(sizeof(t_alias_hist))) == NULL)
    return (-1);
  if ((elem->history = my_strdup(alias)) == NULL)
    return (-1);
  elem->next = *list;
  *list = elem;
  return (0);
}
