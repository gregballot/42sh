/*
** my_autocomplete3.c for yay in /home/locate_a/rendu/42sh/final/42sh/srcs/termcaps
**
** Made by a
** Login   <locate_a@epitech.net>
**
** Started on  Sat May 17 01:54:28 2014 a
** Last update Sun May 25 14:59:23 2014 
*/

#include <curses.h>
#include <term.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "prompt.h"
#include "alias.h"

static int	already_in(char **dup, char *str)
{
  int		i;

  i = 0;
  while (dup && dup[i])
    {
      if (my_strcmp(dup[i], str) == 0)
	return (1);
      ++i;
    }
  return (0);
}

static void	clear_all_pattern(char **pathv)
{
  int		i;

  i = 0;
  while (pathv && pathv[i])
    {
      pathv[i] = my_strdup(&pathv[i][clear_c(pathv[i], '/')]);
      ++i;
    }
}

int		epur_duplicates(char **pathv)
{
  int		i;
  int		j;
  char		**dup;
  int		len;

  j = 0;
  i = 0;
  len = my_tablen(pathv);
  dup = NULL;
  if ((dup = malloc(sizeof(char*) * (len + 1))) == NULL)
    return (-1);
  clear_all_pattern(pathv);
  if (dup)
    dup = memset(dup, 0, sizeof(char*) * (len + 1));
  while (pathv && pathv[i])
    {
      if (already_in(dup, pathv[i]) == 0)
	dup[j++] = pathv[i];
      ++i;
    }
  pathv = dup;
  i = my_tablen(dup) + 1;
  return (i);
}

static int	find_biggest_match(char ** pathv)
{
  int		i;
  int		j;
  int		match;

  i = 1;
  j = 0;
  match = my_strlen(pathv[0]);
  while (pathv[i])
    {
      while ((pathv[0][clear_c(pathv[0], '/') + j] != 0)
	     && pathv[0][clear_c(pathv[0], '/') + j]
	     == pathv[i][clear_c(pathv[i], '/') + j])
	++j;
      if (j < match)
	match = j;
      j = 0;
      ++i;
    }
  return (match);
}

int		check_common_char(char **pathv, char **send,
				  char *str, t_comp *count)
{
  int		match;

  if (pathv == NULL)
    {
      my_putstr(*send);
      return (-1);
    }
  match  = find_biggest_match(pathv);
  if (match > my_strlen(str))
    {
      *send = my_strncat((*send),
			 &pathv[0][clear_c(pathv[0], '/') +
				   my_strlen(&str[clear_c(str, '/')])],
			 match - my_strlen(&str[clear_c(str, '/')]));
      count->compt = my_strlen(*send);
      count->save = my_strlen(*send);
    }
  my_putstr(*send);
  return (0);
}
