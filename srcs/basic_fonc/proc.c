/*
** proc.c for proc in /home/tawfik_e/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Wed Apr 30 14:26:40 2014 tawfik
** Last update Fri May 23 14:52:33 2014 TAWFIK
*/

#include <stdlib.h>
#include <unistd.h>
#include "structs.h"
#include "basic_funct.h"
#include "jobs.h"

t_proc		*my_put_in_list(t_proc *list, pid_t gpid,
				pid_t last_pid, char *cmd)
{
  t_proc	*tmp;

  if ((tmp = malloc(sizeof(t_proc))) == NULL)
    return (NULL);
  tmp->gpid = gpid;
  tmp->last_pid = last_pid;
  if ((tmp->cmd = my_strdup(cmd)) == NULL)
    return (NULL);
  tmp->next = NULL;
  if (list == NULL)
    {
      list = tmp;
      list->prev = NULL;
      return (list);
    }
  else
    {
      tmp->prev = list;
      list->next = tmp;
      return (list->next);
    }
  return (NULL);
}

t_proc		*my_delete_from_list(t_proc *list)
{
  t_proc	*tmp;

  tmp = list;
  if (list->prev)
    list->prev->next = list->next;
  if (list->next)
    list->next->prev = list->prev;
  free(list->cmd);
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  if (tmp == list)
    tmp = tmp->next;
  free(list);
  return (tmp);
}

t_proc		*my_delete_from_list2(t_proc *list)
{
  t_proc	*tmp;

  tmp = list;
  if (list->prev)
    list->prev->next = list->next;
  if (list->next)
    list->next->prev = list->prev;
  free(list->cmd);
  free(list);
  return (tmp->next);
}
