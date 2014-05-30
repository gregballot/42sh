/*
** free_all.c for free_all in /home/abollo_h/rendu/PSU_2013_minishell2/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Feb 23 14:53:54 2014 
** Last update Sat May  3 16:45:03 2014 le-bor_d
*/

#include <stdlib.h>
#include "structs.h"
#include "basic_funct.h"
#include "main_funct.h"

void		free_data(t_list *list)
{
  t_list	*tmp;

  while (list->data)
    {
      tmp = list;
      list = list->next;
      free(tmp->data);
      free(tmp);
    }
  free(list);
}

void		free_stock(char **stock)
{
  int		i;

  i = -1;
  while (stock[++i])
    {
      free(stock[i]);
      stock[i] = NULL;
    }
  free(stock);
  stock = NULL;
}

void		free_all(t_btree **tree, t_list **list)
{
  t_btree	*tmp;

  while (*list)
    free_elem(list);
  while ((*tree)->left)
    {
      tmp = *tree;
      *tree = (*tree)->left;
      free_stock(tmp->right->stock);
      free(tmp);
      tmp = NULL;
    }
}
