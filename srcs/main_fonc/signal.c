/*
** signal.c for signal in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Dec 17 09:25:47 2013
** Last update Sun May 25 17:21:14 2014 TAWFIK
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "main_funct.h"
#include "basic_funct.h"
#include "jobs.h"

extern t_proc	*g_procli;

void		check_all_proc()
{
  t_proc	*proc;
  int		status;
  int		i;

  proc = g_procli;
  i = 0;
  status = 0;
  while (proc != NULL && ++i)
    {
      if (waitpid(proc->last_pid, &status, WNOHANG) == proc->last_pid)
	{
	  if (!WIFSTOPPED(status))
	    {
	      if (printf("[%d] [%s] %d Done.\n", i, proc->cmd, proc->gpid) < 0)
		my_putstr_error("Printf Fail\n");
	      g_procli = my_delete_from_list(proc);
	      check_all_proc();
	      return ;
	    }
	}
      else
	proc = proc->next;
    }
}

void		my_signal(void)
{
  while (isatty(0) && tcgetpgrp(0) != getpgrp())
    if (kill(getpid(), SIGTTIN) == -1)
      my_putstr_error("Syscall kill Fail\n");
  if (signal(SIGTSTP, SIG_IGN) == SIG_ERR ||
      signal(SIGINT, SIG_IGN) == SIG_ERR ||
      signal(SIGQUIT, SIG_IGN) == SIG_ERR ||
      signal(SIGTTIN, SIG_IGN) == SIG_ERR ||
      signal(SIGTTOU, SIG_IGN) == SIG_ERR)
    my_putstr_error("Syscall signal Fail\n");
}
