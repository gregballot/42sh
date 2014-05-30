/*
** verif_val.c for verif_val in /home/abollo_h/rendu/42sh/srcs/main_fonc
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun May 25 12:55:00 2014 
** Last update Sun May 25 12:55:13 2014 
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "basic_funct.h"
#include "structs.h"

int	verif_val(int value, char ***tab)
{
  if ((*tab = my_xmalloc(2 * sizeof(char *))) == NULL)
    return (-1);
  if (value == 0)
    {
      if (((*tab)[0] = my_strdup(";")) == NULL)
	return (-1);
    }
  else if (value == 1)
    {
      if (((*tab)[0] = my_strdup("&&")) == NULL)
	return (-1);
    }
  else
    if (((*tab)[0] = my_strdup("||")) == NULL)
      return (-1);
  return (0);
}
