/*
** find_alias.c for  in /home/ballot_g/rendu/alias
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 18 16:49:14 2014 Gregoire Ballot
** Last update Sun May 25 17:22:54 2014 le-bor_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alias.h"
#include "structs.h"
#include "basic_funct.h"
#include "my_getline.h"

static char		*search_in_list(char *cmd, t_alias *list,
					t_alias *tmp, t_match *match)
{
  char			*ret;

  (void)tmp;
  while (list != NULL)
    {
      if (my_strcmp(cmd, list->alias) == 0)
	{
	  match->ret = list->cmd;
	  break ;
	}
      list = list->next;
    }
  if (match->ret != NULL)
    {
      ret = my_strdup(match->ret);
      match->ret = NULL;
      match->history = NULL;
      return (ret);
    }
  return (NULL);
}

char			*match_alias(char *cmd, t_alias *list)
{
  static t_alias	*tmp = NULL;
  static t_match	match;

  if (tmp == NULL)
    tmp = list;
  return (search_in_list(cmd, list, tmp, &match));
}

static char		**find_alias(char **cpy, int *stop, t_alias *list)
{
  char			*match;
  char			**ret;
  char			*alias;

  *stop = 1;
  alias = NULL;
  if ((match = match_alias(cpy[0], list)) != NULL)
    {
      *stop = 0;
      if ((alias = my_strdup(match)) == NULL)
	return (NULL);
      free(match);
    }
  if ((ret = my_wordtab(alias, ' ')) == NULL)
      return (NULL);
  free(alias);
  return (ret);
}

static char		**search_alias(char **line, t_alias *list)
{
  static int		stop = 0;
  static int		cpt = 0;
  int			ret_h;
  t_alias_hist		*history;
  char			**alias;
  char			**cpy;

  history = NULL;
  if (line == NULL || line[0] == NULL || (cpy = my_duptab(line)) == NULL)
    return (line);
  while (stop == 0 && ++cpt != 40)
    {
      if ((ret_h = push_hist(&(history), cpy[0], list)) == -1)
	return (NULL);
      if (ret_h == -2 || (alias = find_alias(cpy, &stop, list)) == NULL)
	break ;
      if ((cpy = reset_alias(cpy, alias)) == NULL)
	return (line);
    }
  cpt = 0;
  stop = 0;
  free_tab(line);
  my_freehisto(history);
  return (cpy);
}

t_list			*modify_list(t_list *list, t_alias *alias)
{
  t_list		*tmp;

  tmp = list;
  while (list->stock != NULL)
    {
      list->stock = search_alias(list->stock, alias);
      list = list->next;
    }
  return (tmp);
}
