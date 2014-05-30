/*
** git_flags.c for prompt in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Mon May 12 13:45:57 2014 le-bor_d
** Last update Sun May 25 22:54:31 2014 Grégoire BALLOT
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "structs.h"
#include "basic_funct.h"
#include "main_funct.h"

static int		read_fd(int pipefd[2], char *buff)
{
  int			ret;

  if (close(pipefd[1]) == -1)
    write(2, "Close failed!\n", 14);
  if ((ret = read(pipefd[0], buff, 255)) == -1)
    write(2, "Read failed\n", 12);
  if (close(pipefd[0]) == -1)
    write(2, "Close failed!\n", 14);
  return (ret);
}

static int		get_status(t_tab *tab)
{
  static char *const	git[] = {"/usr/bin/git", "status",
				 "--porcelain", NULL};
  char			*buff;
  int			pipefd[2];
  int			ret;
  int			status;
  pid_t			pid;

  if (pipe(pipefd) == -1)
    write(2, "Pipe failed\n", 12);
  if ((buff = my_xmalloc(256)) == NULL)
    return (-1);
  if (!(pid = fork()))
    {
      if (close(pipefd[0]) == -1)
	write(2, "Close failed!!\n", 14);
      if ((dup2(pipefd[1], 1) == -1) || (execve(git[0], git, tab->env)))
	return (tab->exit_flag = -1);
    }
  my_waitpid(pid, &status, 0, 1);
  ret = read_fd(pipefd, buff);
  if (ret > 0)
    return (-1);
  return (0);
}

static void		print_branch(t_tab *tab, char *str, int size)
{
  if (get_status(tab) == -1)
    {
      if (printf("\e[1;31m") < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("\e[1;32m") < 0)
      (void)write(2, "Printf failed\n", 14);
  if (printf("%s\e[0m", &(str[size + 1])) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void			git_flag(t_tab *tab, char *prompt,
				 struct tm *c_time_t, int p)
{
  int			fd;
  int			size;
  char			*str;

  (void)tab;
  (void)prompt;
  (void)c_time_t;
  (void)p;
  if ((fd = open(".git/HEAD", O_RDONLY)) == -1
      || ((str = get_next_line(fd)) == NULL)
      || (my_strncmp(str, "ref: ", 5) != 0))
    {
      if (printf("\e[1;33mNothing\e[0m") < 0)
	(void)write(2, "Printf failed\n", 14);
      return ;
    }
  size = my_strlen(str);
  while (str[size] != '/' && size >= 0)
    --size;
  print_branch(tab, str, size);
  if (close(fd) == -1)
    write(2, "Close failed\n", 13);
}
