/*
** my_strcmp.c for my_strcmp in /home/abollo_h/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Mon Oct  7 16:22:56 2013 
** Last update Sun May 25 13:29:09 2014 
*/

#include "basic_funct.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	n;

  n = 0;
  if (s1 == NULL && s2 == NULL)
    return (0);
  if (!s1 || !s2)
    return (-1);
  while (s1[n] == s2[n])
    {
      if ((s1[n] == '\0') && (s2[n] == '\0'))
	return (0);
      n = n + 1;
    }
  if (s1[n] < s2[n])
    return (-1);
  else
    return (1);
}
