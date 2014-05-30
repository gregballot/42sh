/*
** exec_all.c for exec_all in /home/abollo_h/rendu/42sh/srcs/main_fonc
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Thu May 22 11:40:15 2014 
** Last update Sun May 25 19:18:34 2014 
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_getline.h"
#include "alias.h"
#include "parser.h"
#include "basic_funct.h"
#include "structs.h"
#include "pipe_and_red.h"
#include "main_funct.h"
#include "globbing.h"

int			is_backslash(const char *str, int i)
{
  if (i - 1 >= 0)
    if (str[i - 1] == '\\')
      return (0);
  return (1);
}

void			to_start(t_list **list, int which)
{
  if (which == 0)
    {
      while ((*list)->data)
        (*list) = (*list)->next;
      (*list) = (*list)->next;
    }
  else
    {
      while ((*list)->stock)
        (*list) = (*list)->next;
      (*list) = (*list)->next;
    }
}

static int		init_list(const char *str, t_list **list)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if ((str[i] == D_QUOTE) || (str[i] == QUOTE))
	{
	  if (first_sentence(str, &i, list) == -1)
	    return (-1);
	  if (str[i])
	    i++;
	}
      else
	if (first_word(str, &i, list) == -1)
	  return (-1);
      if (str[i] == ' ')
	i++;
    }
  return (0);
}

int			is_sentence(const char *str, int *bool,
				    int i, char *c)
{
  if (is_backslash(str, i) == 0)
    return (0);
  if ((str[i] == D_QUOTE) || (str[i] == QUOTE))
    {
      if (*bool == 0)
	{
	  *bool = 1;
	  *c = str[i];
	}
      else if (str[i] == *c)
	{
	  *bool = 0;
	  *c = 0;
	}
    }
  return (0);
}

int			exec_all(t_tab *tab, char *str)
{
  t_list		*list;
  t_list		*new;

  list = NULL;
  if (!(str = find_env_var(str, tab, 0)))
    return (-1);
  if ((!str) || !((str = seperate(str, 0, 0, tab))) ||
      !((str = parse_line(str, 0, 0))) || ((init_list(str, &list)) == -1))
    return (-1);
  if (free_blank(&list) == -1)
    return (-1);
  free(str);
  if (((add_null(&list)) == -1) || (count_par(&list) == -1) ||
      (free_blank(&list)) || !((new = lexer(&list))) ||
      ((add_null(&new)) == -1))
    return (-1);
  to_start(&new, 1);
  if (!(new = modify_list(new, tab->alias)))
    return (-1);
  new = replace_tilde(new, tab);
  exec_globbing(new, tab);
  parser(&new, tab);
  free_data(list);
  return (0);
}
