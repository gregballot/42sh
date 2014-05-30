/*
** elem.c for elem in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Dec 31 23:11:39 2013
** Last update Fri May 23 10:36:11 2014 
*/

#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"

int		add_null(t_list **list)
{
  t_list	*add_null;

  if (!(add_null = my_xmalloc(sizeof(t_list))))
    return (-1);
  add_null->prev = (*list)->prev;
  add_null->next = *list;
  add_null->data = NULL;
  add_null->stock = NULL;
  (*list)->prev->next = add_null;
  (*list)->prev = add_null;
  return (0);
}

int		free_list(t_list **list)
{
  int		n;

  n = 0;
  while ((*list)->prev)
    (*list) = (*list)->prev;
  if (*list != NULL)
    {
      while ((*list)->next)
	{
	  *list = (*list)->next;
	  free((*list)->prev->data);
	  free((*list)->prev);
	  n++;
	}
      free((*list)->data);
      free(*list);
    }
  return (0);
}

void		add_elem(t_list **list, char *send)
{
  t_list	*tmp;

  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return ;
  tmp->data = my_strdup(send);
  tmp->prev = (*list)->prev;
  tmp->next = *list;
  (*list)->prev->next = tmp;
  (*list)->prev = tmp;
}

void		del_elem(t_list **list, char *send)
{
  t_list	*tmp;

  *list = (*list)->next;
  tmp = *list;
  (*list)->next->prev = (*list)->prev;
  (*list)->prev->next = (*list)->next;
  *list = (*list)->prev;
  free(tmp->data);
  free(tmp);
  add_elem(list, send);
}

int		free_elem(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  if (*list == (*list)->next)
    {
      free((*list)->data);
      free(*list);
      *list = NULL;
      return (0);
    }
  (*list)->next->prev = (*list)->prev;
  (*list)->prev->next = (*list)->next;
  *list = (*list)->next;
  free(tmp->data);
  free(tmp);
  tmp = NULL;
  return (0);
}
