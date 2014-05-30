/*
** check_error.c for check_error in /home/abollo_h/rendu/42sh
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sat May 24 16:10:18 2014
** Last update Sun May 25 14:44:25 2014 TAWFIK
*/

#include <errno.h>
#include <err.h>
#include <string.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"

static const t_error	g_error[] =
  {
    {SIGHUP, "Hangup.\n"},
    {SIGQUIT, "Quit.\n"},
    {SIGILL, "Illegal instruction.\n"},
    {SIGTRAP, "Trace/breakpoint trap.\n"},
    {SIGABRT, "Aborted.\n"},
    {SIGBUS, "Bus error.\n"},
    {SIGFPE, "Floating point exception\n"},
    {SIGKILL, "Killed.\n"},
    {SIGUSR1, "User defined signal 1.\n"},
    {SIGSEGV, "Segmentation fault (1.5)\n"},
    {SIGUSR2, "User defined signal 2.\n"},
    {SIGPIPE, "Broken pipe.\n"},
    {SIGALRM, "Alarm clock.\n"},
    {SIGTERM, "Terminated.\n"},
    {SIGSTKFLT, "Stack fault.\n"},
    {SIGXCPU, "CPU time limit exceeded.\n"},
    {SIGXFSZ, "File time limit exceeded.\n"},
    {SIGVTALRM, "Virtual timer expired.\n"},
    {SIGPROF, "Profiling timer expired.\n"},
    {SIGPOLL, "I/O possible.\n"},
    {SIGPWR, "Power failure.\n"},
    {SIGSYS, "Bad argument to routine.\n"}
  };

void			my_waitpid(pid_t pid, int *status, int options, int i)
{
  int			j;

  j = -1;
  if (waitpid(pid, status, options | WUNTRACED) == -1)
    {
      write(2, "WAIT FAILED.\n", 13);
      perror(strerror(errno));
    }
  if (i == 0)
    while (++j != sizeof(g_error) / sizeof(g_error[0]))
      if (g_error[j].nbr == WTERMSIG(*status))
  	{
  	  write(2, g_error[j].str, my_strlen(g_error[j].str));
  	  return ;
  	}
}

int			my_tputs(const char *str, int affcnt, int (*ptr)(int))
{
  (void)ptr;
  if (tputs(str, affcnt, my_putchar) == -1)
    {
      write(2, "TPUTS FAILED.\n", 14);
      return (-1);
    }
  return (0);
}

int			mismatch_thing(char *str, int sig)
{
  (void)str;
  if (sig == 1)
    write(2, "Mismatch parenthesis\n", 22);
  if (sig == 2)
    write(2, "Mismatch quote or double quote\n", 31);
  return (0);
}

int			my_puterror(char *str, int sig)
{
  if (sig == 1)
    {
      write(2, "Command '", 9);
      write(2, str, my_strlen(str));
      write(2, "' not found.\n", 13);
    }
  if (sig == 2)
    {
      write(2, "'", 1);
      write(2, str, my_strlen(str));
      write(2, "' not a directory.\n", 19);
    }
  if (sig == 3)
      fprintf(stderr, "If '%s' is not a typo you can use command-not-found\
 to lookup the package that contains it, like this:\n    cnf %s\n", str, str);
  if (sig == 4)
    fprintf(stderr, "dogesh: syntax error near unexpected token `%s'\n",
	    str);
  return (0);
}

int			check_access(t_btree **tree, char *error)
{
  struct stat		buff;

  if (access((*tree)->right->stock[0], F_OK) != 0
      && my_strncmp(error, "./", 2) != 0 && error[0] != '/')
    {
      my_puterror(error, 3);
      return (-1);
    }
  if (access((*tree)->right->stock[0], F_OK) == 0
      && access((*tree)->right->stock[0], X_OK) == 0)
    {
      if (stat((*tree)->right->stock[0], &buff) == -1)
	return (-1);
      if (S_ISDIR(buff.st_mode) == 1)
	{
	  fprintf(stderr, "dogesh: %s: Is a directory\n", error);
	  return (-1);
	}
      free(error);
      return (0);
    }
  warn("%s", error);
  free(error);
  return (-1);
}
