/*
** add_elem.c for add_elem in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Feb 12 10:22:23 2014 
** Last update Tue May 20 12:59:41 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "main_funct.h"
#include "structs.h"
#include "parser.h"

int		count_sent(t_list **list)
{
  t_list	*tmp;
  int		i;
  int		j;
  int		n;

  i = -1;
  j = 0;
  tmp = *list;
  while ((*list)->data)
    {
      while (++i < 6)
	if ((n = search((*list)->data, i, (*list)->quote)) != -1)
	  {
	    *list = tmp;
	    return (j);
	  }
      i = -1;
      j++;
      *list = (*list)->next;
    }
  *list = tmp;
  return (j);
}

int		add_op_bis(t_list **new, t_list **list)
{
  t_list	*tmp;

  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  if ((tmp->stock = my_xmalloc(2 * sizeof(char *))) == NULL)
    return (-1);
  tmp->stock[1] = NULL;
  tmp->data = NULL;
  tmp->quote = (*list)->quote;
  if ((tmp->stock[0] = my_strdup((*list)->data)) == NULL)
    return (-1);
  (*list) = (*list)->next;
  tmp->prev = (*new)->prev;
  tmp->next = *new;
  (*new)->prev->next = tmp;
  (*new)->prev = tmp;
  return (0);
}

int		add_op(t_list **new, t_list **list)
{
  if (*new == NULL)
    {
      if ((*new = my_xmalloc(sizeof(t_list))) == NULL)
	return (-1);
      (*new)->next = *new;
      (*new)->quote = (*list)->quote;
      (*new)->prev = *new;
      (*new)->data = NULL;
      if (((*new)->stock = my_xmalloc(2 * sizeof(char *))) == NULL)
	return (-1);
      (*new)->stock[1] = NULL;
      if (((*new)->stock[0] = my_strdup((*list)->data)) == NULL)
	return (-1);
      (*list) = (*list)->next;
      return (0);
    }
  return (add_op_bis(new, list));
}

int		other_stock(t_list **new, t_list **list)
{
  int		n;
  int		i;
  t_list	*tmp;

  i = -1;
  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  n = count_sent(list);
  if ((tmp->stock = my_xmalloc((n + 1) * sizeof(char *))) == NULL)
    return (-1);
  tmp->stock[n] = NULL;
  tmp->data = NULL;
  tmp->quote = (*list)->quote;
  while (++i != n)
    {
      tmp->stock[i] = my_strdup(clean_backslash(list, &tmp));
      (*list) = (*list)->next;
    }
  tmp->prev = (*new)->prev;
  tmp->next = *new;
  (*new)->prev->next = tmp;
  (*new)->prev = tmp;
  return (0);
}

int		new_stock(t_list **new, t_list **list)
{
  int		n;
  int		i;

  i = -1;
  if (*new == NULL)
    {
      if ((*new = my_xmalloc(sizeof(t_list))) == NULL)
	return (-1);
      (*new)->next = *new;
      (*new)->prev = *new;
      (*new)->quote = (*list)->quote;
      n = count_sent(list);
      if (((*new)->stock = my_xmalloc((n + 1) * sizeof(char *))) == NULL)
	return (-1);
      (*new)->stock[n] = NULL;
      (*new)->data = NULL;
      while (++i != n)
	{
	  (*new)->stock[i] = my_strdup(clean_backslash(list, new));
	  (*list) = (*list)->next;
	}
      return (0);
    }
  return (other_stock(new, list));
}
