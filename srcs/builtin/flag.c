/*
** a_flag.c for flag in /home/abollo_h/rendu/PSU_2013_minishell1
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Mon Dec  9 10:48:37 2013 
** Last update Sun May 25 12:24:17 2014 Grégoire BALLOT
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "basic_funct.h"
#include "structs.h"
#include "my_getline.h"
#include "builtins.h"
#include "main_funct.h"

int			exit_flag(t_tab *tab, t_btree **tree, int value)
{
  tab->exit_flag = 1;
  if (value == -1)
    {
      tab->exit_value = -1;
      return (-1);
    }
  if ((*tree)->right)
    {
      if ((*tree)->right->stock[1] == NULL)
	tab->exit_value = 0;
      else
	tab->exit_value = my_getnbr((*tree)->right->stock[1]);
    }
  return (0);
}

int			cd_flag(t_tab *tab, t_btree **tree)
{
  char			*buff2;
  char			*buff;

  if ((buff = getcwd(NULL, 1024)) == NULL)
    return (-1);
  if ((*tree)->right->stock[1] == NULL)
    cd_tilde(tree, tab, buff);
  else if (my_strcmp((*tree)->right->stock[1], "-") == 0)
    cd_minus(tree, tab, buff);
  else if (chdir((*tree)->right->stock[1]) == -1)
    {
      fprintf(stderr, "dogesh: cd: %s: %s\n",
	      (*tree)->right->stock[1], strerror(errno));
      return (-1);
    }
  if ((buff2 = getcwd(NULL, 1024)) == NULL)
    return (-1);
  change_dir(buff, buff2, tab);
  return (0);
}
