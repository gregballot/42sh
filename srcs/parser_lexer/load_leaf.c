/*
** find_op.c for find_op in /home/abollo_h/rendu/Parser/btree
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Apr 16 14:37:18 2014 
** Last update Sun May 25 12:56:48 2014 
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "basic_funct.h"
#include "verif_val.h"
#include "structs.h"

t_btree		*first_value(int value, int count)
{
  t_btree	*tmp;
  char		**tab;

  init_tree(&tmp);
  if (tmp == NULL)
    return (NULL);
  if (verif_val(value, &tab) == -1)
    return (NULL);
  tab[1] = NULL;
  tmp->par = count;
  tmp->stock = tab;
  return (tmp);
}

void		until_close_par(t_list **list)
{
  int		nbr;

  nbr = 1;
  while (nbr != 0)
    {
      if (((*list)->stock[0][0] == '(') && (!(*list)->quote))
	++nbr;
      else if (((*list)->stock[0][0] == ')') && (!(*list)->quote))
	--nbr;
      (*list) = (*list)->next;
    }
}

void		new_leaf(t_list **list, t_btree **tmp, int count)
{
  if ((*tmp) == NULL)
    return ;
  (*tmp)->stock = (*list)->stock;
  (*list) = ((*list)->stock != NULL) ? ((*list)->next) : ((*list));
  (*tmp)->par = count;
}

t_btree		*load_tree(t_list **list, int *ret)
{
  static int	count = 0;
  t_btree	*tmp;

  init_tree(&tmp);
  if ((*list)->stock && (*list)->stock[0])
    {
      if (((*list)->stock[0][0] == '(') && (!(*list)->quote))
	{
	  (*list) = (*list)->next;
	  ++count;
	  tmp = add_on_tree(tmp, list, 0, count);
	  --count;
	  until_close_par(list);
	  return (tmp);
	}
      else if (((*list)->stock[0][0] == ')') && (!(*list)->quote))
	{
	  *ret = -1;
	  tmp->stock = NULL;
	  tmp->par = count;
	  return (tmp);
	}
    }
  new_leaf(list, &tmp, count);
  return (tmp);
}

t_btree		*exception(t_list **list)
{
  t_btree	*tmp;

  if ((*list)->stock && !find_op((*list)->stock[0], (*list)->quote))
    {
      init_tree(&tmp);
      if (tmp == NULL)
	return (NULL);
      tmp->stock = (*list)->stock;
      (*list) = (*list)->next;
      return (tmp);
    }
  return (NULL);
}
