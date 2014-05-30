/*
** my_tabdup.c for my_tabdup in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/basic_fonc
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Feb 12 11:04:06 2014 
** Last update Fri Apr 25 11:43:06 2014 le-bor_d
*/

#include <stdlib.h>
#include "basic_funct.h"

char	**my_tabdup(char **data)
{
  char	**tab;
  int	n;
  int	i;

  i = -1;
  n = -1;
  if (!data || !data[0])
    return (NULL);
  while (data[++i]);
  if ((tab = my_xmalloc((i + 1) * sizeof(char *))) == NULL)
    return (NULL);
  tab[i] = NULL;
  while (++n != i)
    tab[n] = my_strdup(data[n]);
  return (tab);
}
