/*
** my_strcat.c for my_strcat in /home/abollo_h/minishell1/pipe
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sat Feb  1 11:21:49 2014 
** Last update Sun May 25 12:39:05 2014 
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*my_strcat(const char *s1, char *s2)
{
  int	i;
  int	j;
  char	*ptr;

  j = 0;
  i = my_strlen(s1) + my_strlen(s2);
  if ((ptr = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[i] = 0;
  i = 0;
  while (s1 && s1[j])
    ptr[i++] = s1[j++];
  j = 0;
  while (s2 && s2[j])
    ptr[i++] = s2[j++];
  return (ptr);
}

char	*my_strncat(const char *s1, char *s2, int n)
{
  int	i;
  int	j;
  char	*ptr;

  j = 0;
  i = my_strlen(s1) + n;
  if ((ptr = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[i] = 0;
  i = 0;
  while (s1 && s1[j])
      ptr[i++] = s1[j++];
  j = 0;
  while ((j < n) && (s2))
    ptr[i++] = s2[j++];
  return (ptr);
}
