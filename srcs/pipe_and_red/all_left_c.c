/*
** all_left_c.c for all_left_c.c in /home/abollo_h/rendu/PSU_2013_minishell2/srcs/pipe_and_red
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Feb  9 16:39:12 2014 
** Last update Sun May 25 16:59:50 2014 
*/

#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "basic_funct.h"
#include "parser.h"
#include "pipe_and_red.h"
#include "structs.h"
#include "main_funct.h"
#include "builtins.h"

int	write_on_file(t_tab *tab, t_btree **tree)
{
  int	fd;
  int	ret;
  char	buff[4096];

  ret = 1;
  if ((fd = open("/dev/tty", O_RDWR) == -1))
    return (-1);
  save_arg(&(tab->save), &((*tree)->right->stock[1]), 1);
  buff[0] = 0;
  while	((my_strcmp(buff, (*tree)->right->stock[0]) != 0) && (ret > 0))
    {
      write(fd, "> ", 2);
      ret = read(fd, buff, 4095);
      buff[ret - 1] = 0;
      if ((my_strcmp(buff, (*tree)->right->stock[0]) == 0) ||
	  (ret == 4095))
	{
	  close(fd);
	  return (0);
	}
      write(1, buff, my_strlen(buff));
      write(1, "\n", 1);
    }
  close(fd);
  return (0);
}

int	double_left_c(t_tab *tab, t_btree **tree)
{
  pid_t	pid;
  int	status;

  if (pipe(tab->pipefd[tab->pipe % 2]))
    return (-1);
  if (!(pid = fork()))
    {
      dup2(tab->pipefd[tab->pipe % 2][1], 1);
      close(tab->pipefd[tab->pipe % 2][0]);
      if (write_on_file(tab, tree) == -1)
	return (exit_flag(tab, tree, -1));
      else
	return (exit_flag(tab, tree, 0));
    }
  my_waitpid(pid, &status, 0, 1);
  if (close(tab->pipefd[tab->pipe % 2][1]))
    return (-1);
  tab->pipe++;
  return (0);
}

int	left_c(t_tab *tab, t_btree **tree)
{
  if (tab->info[FD_0] != 0)
    close(tab->info[FD_0]);
  if ((tab->info[FD_0] = open((*tree)->right->stock[0], O_RDONLY)) == -1)
    {
      warn("%s", (*tree)->right->stock[0]);
      return (-1);
    }
  return (0);
}
