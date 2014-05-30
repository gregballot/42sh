/*
** jobs.c for 42 in /home/tawfik_e/Mount/tawfik_e/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Tue May  6 18:41:03 2014 tawfik
** Last update Fri May 23 14:48:45 2014 TAWFIK
*/

#include <stdio.h>
#include "jobs.h"
#include "structs.h"
#include "basic_funct.h"

extern t_proc	*g_procli;

int		jobs_flag(t_tab *a, t_btree **bta)
{
  t_proc	*proc;
  int		i;

  (void)a;
  (void)bta;
  i = 1;
  proc = g_procli;
  while (proc != NULL)
    {
      if (printf("[%d] => {%s} %d\n", i,  proc->cmd, proc->gpid) < 0)
	my_putstr_error("Printf Fail\n");
      proc = proc->next;
      ++i;
    }
  return (0);
}
