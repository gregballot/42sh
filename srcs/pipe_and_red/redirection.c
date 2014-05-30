/*
** redirection.c for redirection in /home/abollo_h/minishell1/pipe
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Fri Jan 31 15:05:13 2014
** Last update Sun May 25 19:49:06 2014 TAWFIK
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe_and_red.h"
#include "parser.h"
#include "basic_funct.h"

static const t_op	g_operator[] =
  {
    {"<<", &double_left_c},
    {"<", &left_c},
    {"2>&1", &err_and_no_right_c},
    {"2>>", &err_double_right_c},
    {">>", &double_right_c},
    {"2>", &err_right_c},
    {">", &right_c}
  };

t_btree			*execution(t_tab *tab, t_btree **tree)
{
  int			j;

  j = -1;
  while (++j != sizeof(g_operator) / sizeof(g_operator[0]))
    {
      if (my_strcmp(g_operator[j].str, (*tree)->stock[0]) == 0)
	{
	  if (g_operator[j].ptr(tab, tree))
	    return (NULL);
	  if (save_arg(&(tab->save), &((*tree)->right->stock[1]), NOT))
	    return (NULL);
	  relink_tree(tree);
	  return (*tree);
	}
    }
  return (NULL);
}

int			my_separator(t_tab *tab, t_btree **tree,
				     int n, t_pid **pid)
{
  if (send_to_arg(tab, tree))
    return (-1);
  exec_command(tab, tree, pid);
  init_to_zero(tab);
  if (n == 0)
    return (execute(tab, tree, pid));
  else if (n == 1)
    {
      if (tab->status != 0)
	while (*tree && (*tree)->stock &&
	       (find_sep((*tree)->stock[0], 0) != 2)
	       && (find_sep((*tree)->stock[0], 0) != 0))
	  relink_tree(tree);
      return (execute(tab, tree, pid));
    }
  if (tab->status == 0)
    while ((*tree)->stock &&
	   (find_sep((*tree)->stock[0], 0) != 1)
	   && (find_sep((*tree)->stock[0], 0) != 0))
      relink_tree(tree);
  return (execute(tab, tree, pid));
}

int			send_to_arg(t_tab *tab, t_btree **tree)
{
  if ((*tree)->right == NULL)
    {
      if (((*tree)->right = malloc(sizeof(t_btree))) == NULL)
	return (-1);
      (*tree)->right->stock = NULL;
      (*tree)->right->par = (*tree)->par;
    }
  if (save_arg(&((*tree)->right->stock), tab->save, CLEAN))
    return (-1);
  tab->save = NULL;
  return (0);
}

int			other_execute(t_tab *tab, t_btree **tree, t_pid **pid)
{
  int			n;

  if (find_op((*tree)->left->stock[0], 0) == 0)
    {
      if (((*tree)->left = execution(tab,
				     &((*tree)->left))) == NULL)
	return (-1);
      return (execute(tab, tree, pid));
    }
  if ((n = find_sep((*tree)->left->stock[0], 0)) >= 0)
    return (my_separator(tab, tree, n, pid));
  return (0);
}

int			execute(t_tab *tab, t_btree **tree, t_pid **pid)
{
  if (!(*tree) || !(*tree)->left || !(*tree)->stock || (tab->exit_flag))
    return (0);
  if (!(*tree)->left->stock || my_strcmp((*tree)->left->stock[0], "&") == 0
      || (my_strcmp((*tree)->left->stock[0], ";") == 0))
    {
      if (send_to_arg(tab, tree))
	return (-1);
      exec_command(tab, tree, pid);
      tab->last_status = tab->status;
      init_to_zero(tab);
      return (execute(tab, tree, pid));
    }
  if (my_strcmp((*tree)->left->stock[0], "|") == 0)
    {
      if ((send_to_arg(tab, tree)) ||
	  ((exec_pipe(tab, tree, 0, pid)) == -1))
	return (-1);
      return (execute(tab, tree, pid));
    }
  return (other_execute(tab, tree, pid));
}
