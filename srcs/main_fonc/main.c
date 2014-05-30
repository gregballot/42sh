/*
** main.c for main in /home/abollo_h/rendu/PSU_2013_minishell1
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Mon Dec  9 10:25:46 2013
** Last update Sun May 25 22:53:50 2014 Grégoire BALLOT
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "pipe_and_red.h"
#include "main_funct.h"
#include "builtins.h"

t_proc		*g_procli = NULL;

int		my_setpath(t_tab *tab)
{
  int		i;

  i = -1;
  if (tab->env)
    while (tab->env[++i])
      {
	if (my_strncmp("PATH=", tab->env[i], 5) == 0)
	  {
	    tab->path = my_wordtab(&(tab->env[i][5]), ':');
	    return (0);
	  }
      }
  return (-1);
}

int		only_space(t_tab *tab)
{
  int		i;

  i = 0;
  while (tab->buff[i] == ' ')
    {
      i++;
      if (tab->buff[i] == 0)
	{
	  free(tab->buff);
	  tab->buff = NULL;
	  return (-1);
	}
    }
  return (0);
}

static void	init_values(t_tab *tab, char **env)
{
  tab->alias = NULL;
  tab->env = NULL;
  tab->bquote = 0;
  tab->list = NULL;
  tab->exit_flag = 0;
  tab->exit_value = 0;
  tab->count = 0;
  if (env != NULL && env[0])
    {
      put_env(env, tab);
      my_setpath(tab);
    }
}

int		main(int argc, char **argv, char **env)
{
  static int	i = 0;
  t_tab		*tab;

  (void)argc;
  if ((tab = my_xmalloc(sizeof(t_tab))) == NULL)
    return (-1);
  if (isatty(0))
    my_signal();
  init_values(tab, env);
  load_conf_file(tab, my_strdup(argv[0]));
  while (!tab->exit_flag && (tab->buff = my_getline(tab, &i)))
    {
      if (only_space(tab) != -1)
  	if ((tab->buff[0] >= 32) && (tab->buff[0] <= 126))
	  {
	    exec_all(tab, my_strdup(tab->buff));
	    tab->count = tab->count + 1;
	  }
      free(tab->buff);
      tab->buff = NULL;
      if (tab->exit_flag == 1)
	return ((unsigned char)tab->exit_value);
    }
  my_putstr("exit\n");
  return (0);
}
