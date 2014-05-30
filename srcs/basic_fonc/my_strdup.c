/*
** my_strdup.c for my_strdup.c in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Dec 18 09:41:16 2013 
** Last update Sat May  3 16:31:34 2014 le-bor_d
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*my_strdup(const char *src)
{
  int	i;
  char	*cpy;

  if (!src || !src[0])
    return (NULL);
  i = 0;
  while (src[i])
    i = i + 1;
  if ((cpy = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  cpy[i] = 0;
  i = 0;
  while (src[i])
    {
      cpy[i] = src[i];
      i = i + 1;
    }
  return (cpy);
}
