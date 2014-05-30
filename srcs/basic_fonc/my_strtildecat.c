/*
** my_strtildecat.c for my_strtildecat in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Dec 25 14:21:33 2013 
** Last update Thu May  8 21:05:50 2014 
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*my_strtildecat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*ptr;

  j = 1;
  if (!s2)
    return (my_strdup(s1));
  i = my_strlen(s1) + my_strlen(s2) - 1;
  if ((ptr = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[i] = 0;
  i = 0;
  while (s1[i])
    {
      ptr[i] = s1[i];
     ++i;
    }
  while (s2[j])
    {
      ptr[i] = s2[j];
      ++i;
      ++j;
    }
  return (ptr);
}
