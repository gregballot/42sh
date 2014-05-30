/*
** my_putchar.c for my_putchar in /home/abollo_h/rendu/PSU_2013_my_select/test/termios
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Dec 31 11:43:11 2013 
** Last update Sat May  3 16:45:38 2014 le-bor_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic_funct.h"

int	my_putchar(int c)
{
  write(1, &c, 1);
  return (c);
}
