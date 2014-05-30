/*
** my_strncmp.c for my_strncmp in /home/abollo_h/rendu/PSU_2013_minishell1
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Mon Dec  9 12:16:11 2013 
** Last update Sat May  3 16:05:11 2014 le-bor_d
*/

#include "basic_funct.h"

int	my_strncmp(const char *s1, const char *s2, const int n)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (i != n)
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i++;
    }
  return (0);
}
