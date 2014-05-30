/*
** add_arg.c for add_arg in /home/abollo_h/rendu/PSU_2013_minishell2/srcs/pipe_and_red
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sat Feb 22 16:28:48 2014 
** Last update Thu May  8 21:12:27 2014 
*/

#include <stdlib.h>
#include "pipe_and_red.h"
#include "basic_funct.h"
#include "structs.h"

void	ret_value(char **stock, int ret)
{
  int	i;

  i = 0;
  if (ret == CLEAN)
    {
      while (stock && stock[i])
	{
	  free(stock[i]);
	  stock[i++] = NULL;
	}
      free(stock);
      stock = NULL;
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    while (tab[++i])
      {
	free(tab[i]);
	tab[i] = NULL;
      }
  free(tab);
}

int	calc_size(char ***save, char **stock)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (*save)
    while ((*save)[i])
      i++;
  if (stock)
    while (stock[j])
      j++;
  i += j;
  return (i);
}

int	save_arg(char ***save, char **stock, int ret)
{
  char	**ptr;
  int	i;
  int	j;

  i = calc_size(save, stock);
  if ((ptr = my_xmalloc((i + 1) * sizeof(char *))) == NULL)
    return (-1);
  ptr[i] = NULL;
  i = 0;
  j = 0;
  while (*save && (*save)[i])
    {
      if ((ptr[i] = my_strdup((*save)[i])) == NULL)
	return (-1);
      i++;
    }
  while (stock && stock[j])
    if ((ptr[i++] = my_strdup(stock[j++])) == NULL)
      return (-1);
  free_tab(*save);
  *save = ptr;
  ret_value(stock, ret);
  return (0);
}
