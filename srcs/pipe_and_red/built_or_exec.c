/*
** built_or_exec.c for built_or_exec in /home/abollo_h/rendu/42sh/srcs/pipe_and_red
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun May 25 16:39:02 2014 
** Last update Sun May 25 16:39:03 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "basic_funct.h"
#include "parser.h"
#include "structs.h"
#include "jobs.h"
#include "builtins.h"
#include "wait.h"
#include "alias.h"
#include "pipe_and_red.h"
#include "main_funct.h"

static const t_op	g_built[] =
  {
    {"setenv", &setenv_flag},
    {"unsetenv", &unsetenv_flag},
    {"env", &env_flag},
    {"cd", &cd_flag},
    {"echo", &echo_flag},
    {"fg", &fg_flag},
    {"bg", &bg_flag},
    {"jobs", &jobs_flag},
    {"alias", &my_alias},
    {"unalias", &my_unalias}
  };

static int	par_or_exit(t_tab *tab, t_btree **tree,
			    t_pid **pid)
{
  if (!my_strcmp("exit", (*tree)->right->stock[0]))
    {
      exit_flag(tab, tree, 0);
      relink_tree(tree);
      return (0);
    }
  if ((*tree)->right->par > (*tree)->par)
    {
      (*pid)->nbr = -1;
      execute(tab, &((*tree)->right), pid);
      relink_tree(tree);
      return (3);
    }
  return (-2);
}

int		built_or_exec(t_tab *tab, t_btree **tree,
			      int n, t_pid **pid)

{
  int		ret;
  int		i;

  i = -1;
  ret = par_or_exit(tab, tree, pid);
  if (ret == 0 || ret == 3)
    return (ret);
  while (++i != (sizeof(g_built) / sizeof(g_built[0])))
    if (my_strcmp(g_built[i].str, (*tree)->right->stock[0]) == 0)
      {
	if (((i == 2) || (i == 4)) && (n == 1))
	  return (-2);
	if ((i = g_built[i].ptr(tab, tree)) == -1)
	  return (-1);
	relink_tree(tree);
        return (0);
      }
  if (exist(tab, tree))
    {
      if (*pid)
	return ((*pid)->nbr = -1);
      return (-1);
    }
  return (-2);
}
