/*
** cd_option.c for cd_option in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Wed Dec 25 14:07:22 2013
** Last update Thu May 15 18:26:21 2014 le-bor_d
*/

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "builtins.h"

int		change_dir(char *buff, char *buff2, t_tab *tab)
{
  int		i;

  i = -1;
  if (tab->env)
    while (tab->env[++i])
      {
	if (buff)
	  if (my_strncmp("OLDPWD=", tab->env[i], 7) == 0)
	    tab->env[i] = my_strcat("OLDPWD=", buff);
	if (buff2)
	  if (my_strncmp("PWD=", tab->env[i], 4) == 0)
	    tab->env[i] = my_strcat("PWD=", buff2);
      }
  return (0);
}

static int	tilde_error(char *stock, t_btree **tree, char *ptr)
{
  if (stock == NULL)
    fprintf(stderr, "dogesh: cd: Home not found\n");
  else if (ptr == NULL)
    fprintf(stderr, "dogesh: cd: %s: %s\n",
	    (*tree)->right->stock[1], strerror(errno));
  else
    fprintf(stderr, "dogesh: cd: %s: %s\n",
	    ptr, strerror(errno));
  free(ptr);
  return (-1);
}

int		cd_tilde(t_btree **tree, t_tab *tab, char *buff)
{
  char		*ptr;
  char		*stock;

  (void)buff;
  ptr = NULL;
  if ((stock = my_getenv(tab->env, "HOME=")) != NULL)
    {
      ptr = my_strtildecat(stock, (*tree)->right->stock[1]);
      if (chdir(ptr) == 0)
	{
	  free(ptr);
	  return (0);
	}
    }
  return (tilde_error(stock, tree, ptr));
}

int		cd_minus(t_btree **tree, t_tab *tab, char *buff)
{
  char		*stock;

  (void)tree;
  (void)buff;
  if ((stock = my_getenv(tab->env, "OLDPWD=")) != NULL)
    {
      if (chdir(stock) == 0)
	return (0);
    }
  if (stock == NULL)
    fprintf(stderr, "dogesh: cd: OLDPWD not set\n");
  else
    fprintf(stderr, "dogesh: cd: %s: %s\n",
	    stock, strerror(errno));
  return (-1);
}
