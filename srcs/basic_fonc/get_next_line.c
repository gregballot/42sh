/*
** get_next_line.c for get_next_line in /home/abollo_h/test/getget
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sun Dec 15 15:26:52 2013
** Last update Sun May 25 15:14:36 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic_funct.h"
#include "structs.h"

static char	*my_realloc(char *stock, char c, int *save, int open)
{
  char		*ptr;
  int		i;

  i = -1;
  if (open == 1)
    {
      if ((ptr = my_xmalloc((*save + 1) * sizeof(char))) == NULL)
	return (NULL);
      while ((++i != *save) && (stock))
	ptr[i] = stock[i];
      ptr[i] = 0;
      *save = 0;
      free(stock);
      return (ptr);
    }
  if ((ptr = my_xmalloc((*save + 1) * sizeof(char))) == NULL)
    return (NULL);
  while ((++i != *save) && (stock))
    ptr[i] = stock[i];
  ptr[i] = c;
  (*save)++;
  free(stock);
  return (ptr);
}

static char	*my_send(t_get *multi, t_comp *count, int *msg)
{
  char		*ptr;

  while ((count->i != count->ret) && (count->ret >= 0))
    {
      if ((multi->buff[count->i] == '\n') ||
	  (multi->buff[count->i] == '\0'))
	{
   	  *msg = 1;
	  ptr = my_realloc(multi->stock,
			   multi->buff[count->i], &(count->save), 1);
	  multi->stock = NULL;
	  count->i++;
	  return (ptr);
	}
       multi->stock = my_realloc(multi->stock,
				 multi->buff[count->i], &(count->save), 0);
      count->i++;
      return (NULL);
    }
  return (NULL);
}

static char	*my_fill(t_get *multi, t_comp *count, int *msg)
{
  char		*ptr;

  if (count->i == count->ret)
    {
      count->i = 0;
      count->ret = read(multi->fd, multi->buff, BUFF_SIZE);
      if (count->ret == -1)
	multi->buff[0] = 0;
      if (count->ret == 0)
	{
	  *msg = 1;
	  count->ret = -1;
	  ptr = my_realloc(multi->stock,
			   multi->buff[count->i], &(count->save), 1);
	  multi->stock = NULL;
	  return (ptr);
	}
    }
  return (NULL);
}

static int	synch_fd_with_buff(t_get **multi, int fd, int id)
{
  static int	begin = 0;
  t_get		*tmp;

  if (begin == 0)
    {
      init_var(multi, fd);
      (*multi)->next = *multi;
    }
  begin = 1;
  id = (*multi)->fd;
  while (((*multi)->fd != fd) && (id != -1))
    {
      *multi = (*multi)->next;
      id = (id == (*multi)->fd) ? -1 : id;
    }
  if ((*multi)->fd == fd)
    return (0);
  if ((tmp = my_xmalloc(sizeof(t_get))) == NULL)
    return (-1);
  init_var(&tmp, fd);
  tmp->next = *multi;
  (*multi)->next = tmp;
  while (((*multi)->fd != fd))
    *multi = (*multi)->next;
  return (0);
}

char		*get_next_line(const int fd)
{
  char		*ptr;
  static t_get	*multi = NULL;

  if (multi == NULL)
    if ((multi = my_xmalloc(sizeof(t_get))) == NULL)
      return (NULL);
  multi->msg = 0;
  if ((synch_fd_with_buff(&multi, fd, 0)) == -1)
    return (NULL);
  if (multi->count.ret == -1)
    return (NULL);
  if (multi->count.save == 0)
    multi->stock = NULL;
  ptr = my_fill(multi, &(multi->count), &(multi->msg));
  if (multi->buff[0] == 0)
    return (NULL);
  if (multi->msg == 1)
    return (ptr);
  ptr = my_send(multi, &(multi->count), &(multi->msg));
  if (multi->msg == 1)
    return (ptr);
  return (get_next_line(fd));
}
