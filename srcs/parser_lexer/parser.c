/*
** parser.c for parser in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Feb 11 11:03:16 2014
** Last update Sun May 25 16:31:54 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "structs.h"
#include "parser.h"
#include "basic_funct.h"
#include "main_funct.h"
#include "pipe_and_red.h"

void		init_to_zero(t_tab *tab)
{
  tab->pipe = 0;
  tab->pid = 0;
  tab->sid = 0;
  tab->info[FD_0] = 0;
  tab->info[FD_1] = 0;
  tab->info[FD_2] = 0;
  tab->pipefd[0][0] = 0;
  tab->pipefd[0][1] = 0;
  tab->pipefd[1][0] = 0;
  tab->pipefd[1][1] = 0;
  tab->spepipe[0] = 0;
  tab->spepipe[1] = 0;
  tab->save = NULL;
}

int		init_tree(t_btree **tree)
{
  if ((*tree = malloc(sizeof(t_btree))) == NULL)
    return (-1);
  (*tree)->stock = NULL;
  (*tree)->left = NULL;
  (*tree)->right = NULL;
  return (0);
}

t_btree		*separtor_found(t_btree *tree, t_list **list,
			       int n, t_btree **tmp)
{
  *list = (*list)->next;
  (*tmp)->left = add_on_tree(tree, list, n, (*tmp)->par);
  return (tree);
}

t_btree		*add_on_tree(t_btree *tree, t_list **list, int value, int count)
{
  int		n;
  int		ret;
  t_btree	*tmp;

  ret = 0;
  if ((tree = first_value(value, count)) == NULL)
    return (NULL);
  tree->left = exception(list);
  while ((*list)->stock)
    {
      tmp = tree;
      while (tmp->left != NULL)
	tmp = tmp->left;
      if ((tmp->right = load_tree(list, &ret)) == NULL)
	return (NULL);
      if (((*list)->stock) &&
	  ((n = find_sep((*list)->stock[0], (*list)->quote)) >= 0))
	return (separtor_found(tree, list, n, &tmp));
      if ((tmp->left = load_tree(list, &ret)) == NULL)
	return (NULL);
      if (ret == -1)
	return (tree);
    }
  return (tree);
}

int		parser(t_list **list, t_tab *tab)
{
  t_pid		*pid;
  t_btree	*tree;

  pid = NULL;
  init_to_zero(tab);
  if ((tree = add_on_tree(tree, list, 0, 0)) == NULL)
    return (-1);
  return (execute(tab, &tree, &pid));
}
