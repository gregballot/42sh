/*
** free_tree.c for free_tree in /home/abollo_h/rendu/Parser/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Fri Apr 18 17:54:43 2014 
** Last update Sat May 24 14:15:59 2014 Grégoire BALLOT
*/

#include <stdlib.h>
#include "structs.h"
#include "pipe_and_red.h"

static void	free_tmp(int i, t_btree *tmp)
{
  while (tmp->stock && tmp->stock[i])
    {
      free(tmp->stock[i]);
      tmp->stock[i++] = NULL;
    }
  free(tmp->stock);
  tmp->stock = NULL;
  free(tmp->right);
  tmp = NULL;
}

void		relink_tree(t_btree **tree)
{
  int		i;
  t_btree	*tmp;

  i = 0;
  tmp = *tree;
  *tree = (*tree)->left;
  if (!tmp->right)
    return ;
  while (tmp->right->stock && tmp->right->stock[i])
    {
      free(tmp->right->stock[i]);
      tmp->right->stock[i++] = NULL;
    }
  i = 0;
  free(tmp->right->stock);
  tmp->right->stock = NULL;
  free(tmp->right);
  tmp->right = NULL;
  free_tmp(i, tmp);
}
