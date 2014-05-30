/*
** xmalloc.c for xmalloc in /home/abollo_h/rendu/BSQ
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Thu Dec  5 08:30:09 2013 
** Last update Sat May  3 16:46:06 2014 le-bor_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "basic_funct.h"

void	*my_xmalloc(long size)
{
  void	*buf;

  if ((buf = malloc(size)) == NULL)
    {
      write(2, "MALLOC FAILED.\n", 15);
      return (NULL);
    }
  return (buf);
}
