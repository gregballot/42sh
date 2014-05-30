/*
** init_var.c for init_var in /home/abollo_h/getnext
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sat Feb  1 21:01:34 2014 
** Last update Sat May  3 16:04:18 2014 le-bor_d
*/

#include <stdlib.h>
#include "structs.h"
#include "basic_funct.h"

void	init_var(t_get **multi, int fd)
{
  (*multi)->stock = NULL;
  (*multi)->fd = fd;
  (*multi)->count.i = 0;
  (*multi)->count.save = 0;
  (*multi)->count.ret = 0;
  (*multi)->msg = 0;
}
