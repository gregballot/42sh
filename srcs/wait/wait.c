/*
** wait.c for wait in /home/abollo_h/rendu/42sh/srcs/wait
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Fri May  9 17:16:33 2014 
** Last update Sat May 24 18:41:25 2014 
*/

#include <stdlib.h>
#include "wait.h"
#include "main_funct.h"
#include "structs.h"

int		fill_pid(t_pid **pid, int nbr)
{
  t_pid		*tmp;

  if ((tmp = malloc(sizeof(t_pid))) == NULL)
    return (-1);
  tmp->next = *pid;
  tmp->jobs = nbr;
  *pid = tmp;
  return (0);
}

int		wait_all(t_pid **pid)
{
  int		i;
  t_pid		*tmp;
  int		status;
  int		save;

  i = 0;
  save = 0;
  while ((*pid) && (((*pid)->jobs)))
    {
      tmp = *pid;
      if ((*pid)->nbr != -1)
	my_waitpid((*pid)->nbr, &status, 0, i);
      if (i == 0)
	save = status;
      *pid = (*pid)->next;
      free(tmp);
      ++i;
    }
  return (save);
}
