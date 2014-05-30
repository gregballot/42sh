/*
** env.c for env in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Dec 17 12:52:57 2013 
** Last update Thu May  8 12:17:56 2014 le-bor_d
*/

#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "builtins.h"
#include "main_funct.h"

int	env_flag(t_tab *tab, t_btree **tree)
{
  int	i;

  (void)tree;
  i = -1;
  if (tab->env)
    while (tab->env[++i])
      {
	my_putstr(tab->env[i]);
	my_putchar(10);
      }
  else
    my_puterror(tab->buff, 1);
  return (0);
}

int	put_env(char **env, t_tab *tab)
{
  int	i;

  i = 0;
  while (env && env[i])
    i++;
  if ((tab->env = my_xmalloc((i + 1) * sizeof(char *))) == NULL)
    return (-1);
  tab->env[i] = NULL;
  i = -1;
  while (env && env[++i])
    tab->env[i] = my_strdup(env[i]);
  return (0);
}
