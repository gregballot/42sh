/*
** exec_command.c for exec_command in /home/abollo_h/rendu/42sh/srcs/pipe_and_red
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sun May 25 16:38:39 2014
Last update Sun May 25 17:45:12 2014 TAWFIK
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "wait.h"
#include "backquote.h"
#include "basic_funct.h"
#include "structs.h"
#include "parser.h"
#include "builtins.h"
#include "alias.h"
#include "built_or_exec.h"
#include "pipe_and_red.h"
#include "main_funct.h"

extern t_proc	*g_procli;

static int	add_on_backquote(t_tab *tab)
{
  int		ret;
  char		*buff;

  if (!tab->bquote || tab->info[FD_1])
    return (0);
  if ((buff = my_xmalloc(1025)) == NULL)
    return (-1);
  while ((ret = read(tab->spepipe[0], buff, 1024)) > 0)
    {
      buff[ret - 1] = 0;
      tab->stock_pipe = my_strfreecat(tab->stock_pipe, buff, 2);
      tab->stock_pipe = my_strfreecat(tab->stock_pipe, " ", 3);
      buff = NULL;
      if ((buff = my_xmalloc(1025)) == NULL)
	return (-1);
      if (ret < 1024)
	break ;
    }
  free(buff);
  close(tab->spepipe[1]);
  close(tab->spepipe[0]);
  return (0);
}

static int	fork_command(t_tab *tab, t_btree **tree, t_pid **pid)
{
  int		n;

  n = 0;
  if (setpgid(0, tab->sid) == -1)
    return (exit_flag(tab, tree, -1));
  if (signal(SIGINT, SIG_DFL) == SIG_ERR ||
      signal(SIGQUIT, SIG_DFL) == SIG_ERR ||
      signal(SIGTSTP, SIG_DFL) == SIG_ERR ||
      signal(SIGTTIN, SIG_DFL) == SIG_ERR ||
      signal(SIGTTOU, SIG_DFL) == SIG_ERR)
    my_putstr_error("Syscall singal fail\n");
  all_fd(tab, DUP);
  if ((n = built_or_exec(tab, tree, 0, pid)) == 0)
    return (exit_flag(tab, tree, 0));
  else if (n == -1)
    return (exit_flag(tab, tree, -1));
  if (execve((*tree)->right->stock[0], (*tree)->right->stock, tab->env))
    return (exit_flag(tab, tree, -1));
  return (0);
}

static	int	check_command(t_tab *tab, t_btree **tree, t_pid **pid, int n)
{
  int		status;
  t_proc	*proc;

  status = 0;
  proc = g_procli;
  while (proc && proc->next != NULL)
    proc = proc->next;
  if ((proc = my_put_in_list(proc, tab->sid, (*pid)->nbr, tab->buff)) == NULL)
    return (-1);
  g_procli = (g_procli == NULL) ? proc : g_procli;
  if (!((*tree)->left->stock && !my_strcmp((*tree)->left->stock[0], "&"))
      || (((*tree)->par) && !my_strcmp((*tree)->left->stock[0], "&")))
    {
      status = ((n != -1)) ? wait_all(pid) : 0;
      if ((!WIFSTOPPED(status)) && (!(tab->bquote)))
	g_procli = my_delete_from_list(proc);
    }
  else
    (*pid)->jobs = 0;
  if (tcsetpgrp(0, getpgrp()) == -1)
    write(2, "Syscall tcsetpgrp failed.\n", 26);
  if (n != -1)
    tab->status = WEXITSTATUS(status) + WIFSIGNALED(status);
  relink_tree(tree);
  return (0);
}

int		exec_command(t_tab *tab, t_btree **tree, t_pid **pid)
{
  int		n;

  if (tab->pipe > 0)
    --tab->pipe;
  if (tab->bquote)
    if (pipe(tab->spepipe) == -1)
      return (-1);
  fill_pid(pid, 1);
  if ((n = built_or_exec(tab, tree, 1, pid)) == 0)
    return (tab->status = 0);
  else if (n == 3)
    return (0);
  else if (n == -1)
    tab->status = -1;
  if (n != -1 && !((*pid)->nbr = fork()))
    return (fork_command(tab, tree, pid));
  all_fd(tab, CLOSE);
  if (tab)
    tab->sid = (tab->sid == 0) ? (*pid)->nbr : tab->sid;
  if (n != -1 && tcsetpgrp(0, tab->sid) == -1)
    write(2, "Syscall tcsetpgrp failed.\n", 26);
  if (n != -1)
    if (add_on_backquote(tab) == -1)
      return (-1);
  return (check_command(tab, tree, pid, n));
}
