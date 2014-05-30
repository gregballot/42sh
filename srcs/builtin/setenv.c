/*
** build_env.c for build_env in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Dec 17 13:35:49 2013
** Last update Sun May 25 19:03:48 2014 le-bor_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "builtins.h"
#include "main_funct.h"

int	my_setenv(t_tab *tab, t_btree **tree)
{
  char	**save;
  int	i;

  i = 0;
  while (tab->env && tab->env[i])
    ++i;
  if ((save = my_xmalloc((i + 2) * sizeof(char *))) == NULL)
    return (-1);
  i = -1;
  while (tab->env && tab->env[++i])
    save[i] = my_strdup(tab->env[i]);
  save[i] = add_equal((*tree)->right->stock);
  save[i + 1] = NULL;
  if (tab->env != NULL)
    free_tab(tab->env);
  tab->env = my_duptab(save);
  my_setpath(tab);
  return (0);
}

int	is_exist(t_tab *tab, t_btree **tree)
{
  if (tab->env != NULL)
    if (my_get_special_env(tab->env,
			   my_strdup((*tree)->right->stock[1])) != NULL)
      {
	my_unsetenv(tab, tree);
	return (0);
      }
  return (0);
}

int	setenv_flag(t_tab *tab, t_btree **tree)
{
  int	i;

  i = -1;
  while ((*tree)->right->stock[++i]);
  if (i != 3)
    {
      write(2, "USAGE: setenv [NAME] [WORDS]\n", 29);
      return (-1);
    }
  is_exist(tab, tree);
  my_setenv(tab, tree);
  return (0);
}
