/*
** add_equal.c for add_equal.c in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/builtin
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Feb 16 13:46:50 2014 
** Last update Sun May  4 18:32:40 2014 le-bor_d
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*add_equal(char **stock)
{
  int	i;
  int	j;
  int	n;
  char	*ptr;

  i = -1;
  n = -1;
  j = 0;
  while (stock != NULL && stock[1] != NULL && stock[1][++i]);
  while (stock != NULL && stock[2] != NULL && stock[2][++n]);
  i += n + 1;
  if ((ptr = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[i] = 0;
  i = 0;
  while (stock != NULL && stock[1] != NULL && stock[1][i])
    ptr[j++] = stock[1][i++];
  ptr[j++] = '=';
  i = 0;
  while (stock != NULL && stock[2] != NULL && stock[2][i])
    ptr[j++] = stock[2][i++];
  return (ptr);
}
