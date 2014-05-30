/*
** autocomp_glob.c for yay in /home/locate_a/rendu/42sh/final/42sh/srcs/termcaps
**
** Made by a
** Login   <locate_a@epitech.net>
**
** Started on  Wed May 21 18:37:04 2014 a
** Last update Sun May 25 20:28:24 2014 TAWFIK
*/

#include <curses.h>
#include <term.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <glob.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "prompt.h"
#include "alias.h"

void	aff_glob(glob_t *globbuf)
{
  int	i;

  i = 0;
  my_putchar('\n');
  while (i < (int)globbuf->gl_pathc)
    {
      if (globbuf->gl_pathv)
	my_putstr(&globbuf->gl_pathv[i][clear_c(globbuf->gl_pathv[i], '/')]);
      ++i;
      if (i < ((int)globbuf->gl_pathc))
	my_putchar('\n');
    }
  my_putchar('\n');
}

int	glob_here(glob_t *globbuf, char **send, t_tab *stock)
{
  int	ret;

  ret = 0;
  if ((ret = glob( "*", GLOB_MARK
		  | GLOB_ERR, NULL, globbuf)) == -1
      || ret == GLOB_NOMATCH)
    return (my_glob_return(globbuf, NULL, -1));
  aff_glob(globbuf);
  prompt(stock);
  my_putstr(*send);
  return (my_glob_return(globbuf, NULL, 0));
}

int	clear_c(char *send, char delim)
{
  int	i;

  i = my_strlen(send);
  while (i)
    {
      if (send[i] == delim && i != (my_strlen(send) - 1))
	return (i + 1);
      --i;
    }
  return (0);
}

int	arg_complete(char **send, t_tab *stock,
		     t_comp *count, glob_t *globbuf)
{
  int	j;
  int	ret;
  char	**cmd;

  if ((cmd = my_wordtab((*send), ' ')) == NULL)
    return (-1);
  j = my_tablen(cmd);
  ret = 0;
  if ((ret = glob(my_strcat(my_strdup(cmd[j]), "*"), GLOB_MARK
		  | GLOB_ERR, NULL, globbuf)) == -1
      || ret == GLOB_NOMATCH)
    return (my_glob_return(globbuf, NULL, -1));
  if (globbuf->gl_pathc == 1)
    return (one_match(send, cmd[j], globbuf, count));
  else
    aff_glob(globbuf);
  prompt(stock);
  check_common_char(globbuf->gl_pathv, send, cmd[j], count);
  free_tab(cmd);
  return (my_glob_return(globbuf, NULL, 0));
}
