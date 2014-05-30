/*
** background.c for lol in /home/tawfik_e/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Wed Apr 30 19:01:01 2014 tawfik
** Last update Sat May 24 16:07:23 2014 TAWFIK
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "basic_funct.h"
#include "main_funct.h"
#include "structs.h"
#include "jobs.h"

extern t_proc	*g_procli;

int		cont_proc(t_proc *proc)
{
  int		status;

  if (kill((-1) * proc->gpid, SIGCONT) == -1)
    {
      my_putstr_error("Syscall kill failed.\n");
      return (1);
    }
  if (tcsetpgrp(0, proc->gpid) == -1)
    write(2, "Syscall tcsetpgrp failed.\n", 26);
  my_waitpid(proc->last_pid, &status, 0, 1);
  if (tcsetpgrp(0, getpgrp()) == -1)
    write(2, "Syscall tcsetpgrp failed.\n", 26);
  if (!WIFSTOPPED(status))
    g_procli = my_delete_from_list(proc);
  return (0);
}

int		cont_back_proc(t_proc *proc)
{
  if (kill((-1) * proc->gpid, SIGCONT) == -1)
    {
      my_putstr_error("Syscall kill failed.\n");
      return (1);
    }
  if (tcsetpgrp(0, getpgrp()) == -1)
    write(2, "Syscall tcsetpgrp failed.\n", 26);
  return (0);
}
