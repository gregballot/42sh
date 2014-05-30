/*
** my_strlen.c for my_strlen in /home/abollo_h/rendu/Piscine-C-Jour_04
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Thu Oct  3 10:46:00 2013 
** Last update Sat May  3 16:04:59 2014 le-bor_d
*/

#include <stdlib.h>
#include "basic_funct.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}
