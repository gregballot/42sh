/*
** pipe.c for pipe in /home/abollo_h/rendu/42sh/srcs/pipe_and_red
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sun May 25 16:38:25 2014
** Last update Sun May 25 17:45:02 2014 TAWFIK
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "basic_funct.h"
#include "parser.h"
#include "structs.h"
#include "jobs.h"
#include "builtins.h"
#include "wait.h"
#include "alias.h"
#include "pipe_and_red.h"
#include "built_or_exec.h"
#include "main_funct.h"

int		exist(t_tab *tab, t_btree **tree)
{
  int		j;
  char		*ptr;
  char		*error;

  j = -1;
  if (((ptr = my_strdup((*tree)->right->stock[0])) == NULL) ||
      ((error = my_strdup((*tree)->right->stock[0])) == NULL))
    return (-1);
  if (tab->path && (*tree)->right->stock[0] != NULL
      && (*tree)->right->stock[0][0] != '/'
      && my_strncmp("./", (*tree)->right->stock[0], 2) != 0)
    {
      if (tab->path[++j] != NULL)
	(*tree)->right->stock[0] = my_strslashcat(tab->path[++j], ptr);
      while ((access((*tree)->right->stock[0], F_OK)) && (tab->path[++j]))
	{
	  if (access((*tree)->right->stock[0], F_OK) != 0)
	    free((*tree)->right->stock[0]);
	  (*tree)->right->stock[0] = my_strslashcat(tab->path[j], ptr);
	}
    }
  free(ptr);
  if (check_access(tree, error) == 0)
    return (0);
  return (-1);
}

void		fd_is_on(t_tab *tab, int status)
{
  if (status == DUP)
    {
      if (tab->info[FD_0] > 0)
	dup2(tab->info[FD_0], 0);
      if (tab->info[FD_1] > 0)
	dup2(tab->info[FD_1], 1);
    }
  else if (status == CLOSE)
    {
      if (tab->info[FD_0] > 0)
	close(tab->info[FD_0]);
      if (tab->info[FD_1] > 0)
	close(tab->info[FD_1]);
      tab->info[FD_1] = 0;
      tab->info[FD_0] = 0;
    }
}

static int	fork_pipe(t_tab *tab, t_btree **tree, t_pid **pid, int n)
{
  if (setpgid(0, tab->sid) == -1)
    return (exit_flag(tab, tree, -1));
  if (signal(SIGINT, SIG_DFL) == SIG_ERR ||
      signal(SIGQUIT, SIG_DFL) == SIG_ERR ||
      signal(SIGTSTP, SIG_DFL) == SIG_ERR ||
      signal(SIGTTIN, SIG_DFL) == SIG_ERR ||
      signal(SIGTTOU, SIG_DFL) == SIG_ERR)
    my_putstr_error("Syscall signal fail\n");
  if (tab->pipe != 0)
    if ((dup2(tab->pipefd[(tab->pipe - 1) % 2][0], 0)))
      return (exit_flag(tab, tree, -1));
  if ((dup2(tab->pipefd[tab->pipe % 2][1], 1) == -1) ||
      (close(tab->pipefd[tab->pipe % 2][0])))
    return (exit_flag(tab, tree, -1));
  if ((n = built_or_exec(tab, tree, 0, pid)) == -1)
    return (exit_flag(tab, tree, -1));
  else if (n == 0)
    return (exit_flag(tab, tree, 0));
  fd_is_on(tab, DUP);
  if (execve((*tree)->right->stock[0], (*tree)->right->stock, tab->env))
    return (exit_flag(tab, tree, -1));
  return (0);
}

int		exec_pipe(t_tab *tab, t_btree **tree, int status, t_pid **pid)
{
  int		n;

  n = 0;
  (void)status;
  fill_pid(pid, 1);
  if (pipe(tab->pipefd[tab->pipe % 2]) == -1)
    return (-1);
  if (!((*pid)->nbr = fork()))
    return (fork_pipe(tab, tree, pid, n));
  if ((close(tab->pipefd[tab->pipe % 2][1])) == -1)
    return (-1);
  fd_is_on(tab, CLOSE);
  if (tab)
    {
      tab->sid = (tab->sid == 0) ? (*pid)->nbr : tab->sid;
      tab->pipe++;
    }
  relink_tree(tree);
  return (0);
}

void		all_fd(t_tab *tab, int action)
{
  if (action == CLOSE)
    {
      if (tab->pipefd[tab->pipe % 2][0] > 0)
	close(tab->pipefd[tab->pipe % 2][0]);
      if (tab->info[FD_0] > 0)
	close(tab->info[FD_0]);
      if (tab->info[FD_1] > 0)
	close(tab->info[FD_1]);
      if (tab->info[FD_2] > 0)
	close(tab->info[FD_2]);
      if (!tab->info[FD_1] && tab->bquote)
	close(tab->spepipe[1]);
      return ;
    }
  if (tab->pipefd[tab->pipe % 2][0] > 0)
    dup2(tab->pipefd[tab->pipe % 2][0], 0);
  if (tab->info[FD_0] > 0)
    dup2(tab->info[FD_0], 0);
  if (tab->info[FD_1] > 0)
    dup2(tab->info[FD_1], 1);
  if (tab->info[FD_2] > 0)
    dup2(tab->info[FD_2], 2);
  if (!tab->info[FD_1] && tab->bquote)
    dup2(tab->spepipe[1], 1);
}
