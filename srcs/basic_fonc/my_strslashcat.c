/*
** my_strslashcat.c for my_strslashcat in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Wed Dec 18 14:12:04 2013
** Last update Sun May 25 20:06:59 2014 TAWFIK
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*my_strslashcat(const char *s1, const char *s2)
{
  char	*ptr;
  int	i;
  int	j;

  ptr = NULL;
  i = 0;
  j = 0;
  while (s1 && s1[j])
    ++j;
  while (s2 && s2[i])
    ++i;
  if ((ptr = my_xmalloc((i + j + 2) * sizeof(char))) == NULL)
    return (NULL);
  ptr[i + j + 1] = 0;
  i = -1;
  j = 0;
  while (s1 && s1[++i])
    ptr[i] = s1[i];
  ptr[i++] = '/';
  while (s2 && s2[j])
    ptr[i++] = s2[j++];
  return (ptr);
}
