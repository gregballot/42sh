/*
** add_elem.c for add_elem.c in /home/abollo_h/minishell1/pipe
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Jan 26 17:50:06 2014 
** Last update Sun May 25 12:42:15 2014 
*/

#include <stdlib.h>
#include "my_getline.h"
#include "main_funct.h"
#include "basic_funct.h"
#include "structs.h"

char		*my_add_char(char *str, char c, int n)
{
  char		*ptr;

  if ((ptr = my_xmalloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[n] = 0;
  n = 0;
  while (str && str[n])
    {
      ptr[n] = str[n];
      n++;
    }
  ptr[n] = c;
  free(str);
  return (ptr);
}

int		other_sentence(t_list **list, int n,
			       const char *str, int save)
{
  t_list	*tmp;

  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  if ((tmp->data = my_xmalloc((n + 1) * sizeof(char))) == NULL)
    return (-1);
  tmp->data[n--] = 0;
  while (n >= 0)
    tmp->data[n--] = str[save--];
  tmp->quote = 1;
  tmp->prev = (*list)->prev;
  tmp->next = *list;
  (*list)->prev->next = tmp;
  (*list)->prev = tmp;
  return (0);
}

int		first_sentence(const char *str, int *i, t_list **list)
{
  int		n;
  int		save;
  char		c;

  c = str[*i];
  n = 0;
  while ((str[++(*i)]) && (str[*i] != c))
    n++;
  save = (*i) - 1;
  if (*list == NULL)
    {
      if (((*list = my_xmalloc(sizeof(t_list))) == NULL) ||
	  ((*list)->data = my_xmalloc((n + 1) * sizeof(char))) == NULL)
	return (-1);
      (*list)->prev = *list;
      (*list)->next = *list;
      (*list)->data[n--] = 0;
      (*list)->quote = 1;
      while (n >= 0)
	(*list)->data[n--] = str[save--];
      return (0);
    }
  if (other_sentence(list, n, str, save) == -1)
    return (-1);
  return (0);
}

int		other_word(const char *str, t_list **list, int c, int *i)
{
  int		n;
  t_list	*tmp;

  n = 0;
  c = *i;
  while (((str[*i] != ' ') || !(is_backslash(str, *i))) && (str[*i]))
    ++(*i);
  if ((tmp = my_xmalloc(sizeof(t_list))) == NULL)
    return (-1);
  if ((tmp->data = my_xmalloc(((*i - c) + 1) * sizeof(char))) == NULL)
    return (-1);
  tmp->data[*i - c] = 0;
  while (((str[c] != ' ') || !(is_backslash(str, c))) && (str[c]))
    tmp->data[n++] = str[c++];
  tmp->prev = (*list)->prev;
  tmp->next = *list;
  tmp->quote = 0;
  (*list)->prev->next = tmp;
  (*list)->prev = tmp;
  return (0);
}

int		first_word(const char *str, int *i, t_list **list)
{
  int		c;
  int		n;

  c = 0;
  n = -1;
  if (*list == NULL)
    {
      if ((*list = my_xmalloc(sizeof(t_list))) == NULL)
	return (-1);
      (*list)->prev = *list;
      (*list)->next = *list;
      (*list)->quote = 0;
      while (((str[*i] != ' ') || !(is_backslash(str, *i))) && (str[*i]))
	(*i)++;
      if (((*list)->data = my_xmalloc((*i + 1) * sizeof(char))) == NULL)
	return (-1);
      (*list)->data[*i] = 0;
      while (++n != *i)
	(*list)->data[n] = str[n];
      return (0);
    }
  if (other_word(str, list, c, i) == -1)
    return (-1);
  return (0);
}
