/*
** unsetenv.c for unsetenv in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Dec 17 22:49:42 2013
** Last update Sat May 24 14:47:36 2014 TAWFIK
*/

#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "builtins.h"
#include "main_funct.h"

int	verify_path(t_tab *tab, t_btree **tree, char **save)
{
  int	i;

  (void)tree;
  i = -1;
  if (tab->env)
    while (tab->env[++i])
      free(tab->env[i]);
  free(tab->env);
  i = -1;
  tab->env = save;
  if (tab->path)
    while (tab->path[++i])
      free(tab->path[i]);
  free(tab->path);
  tab->path = NULL;
  i = -1;
  my_setpath(tab);
  return (0);
}

int	init_save(char ***save, t_tab *tab)
{
  int	i;

  i = 0;
  if (tab->env)
    while (tab->env[i])
      i++;
  if ((*save = my_xmalloc(i * sizeof(char *))) == NULL)
    return (-1);
  (*save)[i - 1] = NULL;
  return (0);
}

int	my_unsetenv(t_tab *tab, t_btree **tree)
{
  char	**save;
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  init_save(&save, tab);
  tmp = my_strcat((*tree)->right->stock[1], my_strdup("="));
  while (tab->env[i] != NULL
	 && my_strncmp(tmp, tab->env[i], my_strlen(tmp)) != 0)
    save[j++] = my_strdup(tab->env[i++]);
  if (tab->env[i])
    ++i;
  while (tab->env[i] != NULL)
    save[j++] = my_strdup(tab->env[i++]);
  save[j] = NULL;
  free(tmp);
  if (verify_path(tab, tree, save) == -1)
    return (-1);
  return (0);
}

int	unsetenv_flag(t_tab *tab, t_btree **tree)
{
  int	i;

  i = 0;
  while ((*tree)->right->stock[i])
    ++i;
  if (i != 2)
    return (-1);
  i = -1;
  if (tab->env)
    while (tab->env[++i])
      {
	if (my_strncmp((*tree)->right->stock[1],
		       tab->env[i], my_strlen((*tree)->right->stock[1])) == 0)
	  {
	    if (my_unsetenv(tab, tree) == -1)
	      return (-1);
	    else
	      return (0);
	  }
      }
  return (0);
}
