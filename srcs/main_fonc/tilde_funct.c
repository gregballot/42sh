/*
** tilde_funct.c for tilde in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Tue Apr 29 17:20:07 2014 le-bor_d
** Last update Thu May  8 14:34:30 2014 le-bor_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "basic_funct.h"
#include "main_funct.h"

static char	*my_pwent(char *str)
{
  struct passwd	*infos;
  char		*ptr;

  ptr = NULL;
  while ((infos = getpwent()) != NULL)
    if (my_strcmp(infos->pw_name, &(str[1])) == 0)
      {
	ptr = my_strslashcat(infos->pw_dir,
			     &(str[my_strlen(infos->pw_name) + 1]));
	endpwent();
	return (ptr);
      }
  endpwent();
  return (NULL);
}

static char	*modify_tilde(char *str, t_tab *tab)
{
  char		*ptr;
  char		*stock;

  ptr = NULL;
  if (str != NULL && str[1] != '/' && str[1] != '\0')
    {
      if ((ptr = my_pwent(str)) != NULL)
	{
	  free(str);
	  return (ptr);
	}
      else
	return (str);
    }
  if ((stock = my_getenv(tab->env, "HOME=")) != NULL)
    {
      ptr = my_strtildecat(stock, str);
      free(str);
      return (ptr);
    }
  return (str);
}

t_list		*replace_tilde(t_list *new, t_tab *tab)
{
  t_list	*tmp;
  int		i;

  tmp = new;
  while (new->stock != NULL)
    {
      i = -1;
      while (new->stock[++i] != NULL)
	if (new->stock[i][0] == '~')
	  new->stock[i] = modify_tilde(new->stock[i], tab);
      new = new->next;
    }
  return (tmp);
}
