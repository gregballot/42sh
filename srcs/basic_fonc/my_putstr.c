/*
** my_putstr.c for my_putstr in /home/abollo_h/rendu/Piscine-C-Jour_04
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Thu Oct  3 09:14:34 2013 
** Last update Sat May  3 16:45:42 2014 le-bor_d
*/

#include <unistd.h>
#include "basic_funct.h"

int	my_putstr(const char *str)
{
  int	count;

  count = 0;
  if (str == 0)
    return (0);
  while (*(str + count) != '\0')
    {
      my_putchar(*(str + count));
      count = count + 1;
    }
  return (0);
}

int	my_putstr_error(const char *str)
{
  int	count;

  count = 0;
  if (str == 0)
    return (-1);
  while (*(str + count) != '\0')
    {
      write(2, (str + count), 1);
      count = count + 1;
    }
  return (-1);
}
