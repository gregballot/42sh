/*
** clean_backslash.c for clean_backslash in /home/abollo_h/rendu/42sh/srcs/main_fonc
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Thu May  1 15:24:24 2014 
** Last update Sat May  3 19:16:29 2014 
*/

#include "structs.h"
#include "main_funct.h"

char		*clean_backslash(t_list **list, t_list **new)
{
  int		i;
  int		n;

  i = -1;
  if (!(*list)->quote)
    while ((*list)->data[++i])
      if ((*list)->data[i] == '\\')
	{
	  (*new)->quote = 3;
	  n = i;
	  while ((*list)->data[n])
	    {
	      (*list)->data[n] = (*list)->data[n + 1];
	      n++;
	    }
	}
  return ((*list)->data);
}
