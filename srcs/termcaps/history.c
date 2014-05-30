/*
** history.c for history in /home/abollo_h/rendu/42sh/srcs/termcaps
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Mon Apr 28 15:33:48 2014 
** Last update Sat May 24 18:40:53 2014 
*/

#include <stdlib.h>
#include "structs.h"
#include "basic_funct.h"
#include "main_funct.h"
#include "termcaps.h"

static void	elem_del(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp->next->next)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
  tmp = tmp->next;
}

static int	new_list(t_list **list, char *send)
{
  if ((*list = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  (*list)->next = NULL;
  (*list)->data = my_strdup(send);
  (*list)->prev = NULL;
  return (0);
}

int		init_list(t_list **list, char *send, int *i)
{
  t_list	*tmp;

  if (!(*list))
    return (new_list(list, send));
  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  while ((*list)->prev)
    *list = (*list)->prev;
  tmp->next = *list;
  (*list)->prev = tmp;
  tmp->prev = NULL;
  tmp->data = my_strdup(send);
  (*list) = tmp;
  if (*i >= 15)
    {
      elem_del(list);
      --(*i);
    }
  return (0);
}
