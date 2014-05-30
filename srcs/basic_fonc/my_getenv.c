/*
** my_getterm.c for my_getterm in /home/abollo_h/rendu/PSU_2013_my_select/test
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Dec 29 17:24:45 2013 
** Last update Sat May  3 16:35:54 2014 le-bor_d
*/

#include <stdlib.h>
#include "basic_funct.h"

char	*my_getenv(char **env, const char *var)
{
  int	i;

  i = 0;
  if (env)
    while (env && env[i])
      {
	if (my_strncmp(env[i], var, my_strlen(var)) == 0)
	  return (&(env[i][my_strlen(var)]));
	i++;
      }
  return (NULL);
}
