/*
** all_right_c.c for all_right_c in /home/abollo_h/rendu/PSU_2013_minishell2/srcs/pipe_and_red
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sun Feb  9 13:24:45 2014
** Last update Sun May 25 16:59:42 2014 
*/

#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "basic_funct.h"
#include "parser.h"
#include "structs.h"
#include "pipe_and_red.h"

int	err_and_no_right_c(t_tab *tab, t_btree **tree)
{
  if (((*tree)->right->stock[0] =
       my_strdup((*tree)->right->stock[0])) == NULL)
    return (-1);
  if (tab->info[FD_1] != 0)
    if ((close(tab->info[FD_1])) == -1)
      return (-1);
  if (tab->info[FD_2] != 0)
    if ((close(tab->info[FD_2])) == -1)
      return (-1);
  if ((tab->info[FD_1] = open((*tree)->right->stock[0],
			      O_CREAT | O_WRONLY | O_TRUNC,
			      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      warn("%s", (*tree)->right->stock[0]);
      return (-1);
    }
  if ((tab->info[FD_2] = dup(tab->info[FD_1])) == -1)
    return (-1);
  return (0);
}

int	err_double_right_c(t_tab *tab, t_btree **tree)
{
  if (((*tree)->right->stock[0] =
       my_strdup((*tree)->right->stock[0])) == NULL)
    return (-1);
  if (tab->info[FD_2] != 0)
    if ((close(tab->info[FD_2])) == -1)
      return (-1);
  if ((tab->info[FD_2] = open((*tree)->right->stock[0],
			      O_CREAT | O_WRONLY | O_APPEND,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      warn("%s", (*tree)->right->stock[0]);
      return (-1);
    }
  return (0);
}

int	double_right_c(t_tab *tab, t_btree **tree)
{
  if (!((((*tree)) != NULL) && ((*tree)->right != NULL)))
    return (-1);
  if (((*tree)->right->stock[0] =
       my_strdup((*tree)->right->stock[0])) == NULL)
    return (-1);
  if (tab->info[FD_1] != 0)
    if ((close(tab->info[FD_1])) == -1)
      return (-1);
  if ((tab->info[FD_1] = open((*tree)->right->stock[0],
			      O_CREAT | O_WRONLY | O_APPEND,
			      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-1);
  return (0);
}

int	err_right_c(t_tab *tab, t_btree **tree)
{
  if (((*tree)->right->stock[0] =
       my_strdup((*tree)->right->stock[0])) == NULL)
    return (-1);
  if (tab->info[FD_2] != 0)
    if ((close(tab->info[FD_2])) == -1)
      return (-1);
  if ((tab->info[FD_2] = open((*tree)->right->stock[0],
			      O_CREAT | O_WRONLY | O_TRUNC,
			      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      warn("%s", (*tree)->right->stock[0]);
      return (-1);
    }
  return (0);
}

int	right_c(t_tab *tab, t_btree **tree)
{
  if (!((((*tree)) != NULL) && ((*tree)->right != NULL)))
    return (-1);
  if (((*tree)->right->stock[0] =
       my_strdup((*tree)->right->stock[0])) == NULL)
    return (-1);
  if (tab->info[FD_1] != 0)
    if ((close(tab->info[FD_1])) == -1)
      return (-1);
  if ((tab->info[FD_1] = open((*tree)->right->stock[0],
			      O_CREAT | O_WRONLY | O_TRUNC,
			      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      warn("%s", (*tree)->right->stock[0]);
      return (-1);
    }
  return (0);
}
