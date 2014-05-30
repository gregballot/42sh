/*
** my_autcomplete2.c for yay in /home/locate_a/rendu/42sh/final/42sh/srcs/termcaps
**
** Made by a
** Login   <locate_a@epitech.net>
**
** Started on  Mon May  5 23:33:16 2014 a
** Last update Sun May 25 20:34:40 2014 TAWFIK
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

int		disclaimer(glob_t *globuf, t_tab *stock, char **send)
{
  int		ret;
  char		buff[1];

  my_putchar('\n');
  if (printf(DISCLAIMER, (int)globuf->gl_pathc) < 0)
    my_putstr_error("Printf Fail\n");
  while ((ret = read(0, buff, 1)) > 0)
    if (buff[0] == 'y')
      {
	aff_glob(globuf);
	prompt(stock);
	if (send != NULL)
	  my_putstr(*send);
	return (0);
      }
    else if (buff[0] == 'n')
      {
	my_putchar('\n');
	prompt(stock);
	if (send != NULL)
	  my_putstr(*send);
	return (0);
      }
  return (my_glob_return(globuf, NULL, ret));
}

int		bin_completion(char **send, t_tab *stock
			       , glob_t *globuf, t_comp *count)
{
  char		*path;
  int		i;

  i = 0;
  if ((!(stock && stock->path && send)) ||
      (!(path = my_strslashcat(my_strdup(stock->path[0]), my_strdup((*send))))
       || (glob(my_strcat(my_strdup(path), "*"), GLOB_MARK, NULL, globuf) < 0)))
    return (-1);
  while (stock->path[++i] != NULL)
    {
      path = my_strslashcat(my_strdup(stock->path[i]), my_strdup((*send)));
      if ((glob(my_strcat(my_strdup(path), "*"), GLOB_ERR
		| GLOB_APPEND, NULL, globuf)) == -1)
	return (my_glob_return(globuf, path, -1));
    }
  if (globuf->gl_pathc <= 0)
    return (my_glob_return(globuf, path, -1));
  globuf->gl_pathc = epur_duplicates(globuf->gl_pathv);
  if (globuf->gl_pathc > 50)
    return (disclaimer(globuf, stock, send));
  else
    aff_glob(globuf);
  prompt(stock);
  check_common_char(globuf->gl_pathv, send, *send, count);
  return (my_glob_return(globuf, path, 0));
}

int		every_glob(t_tab *stock, glob_t *globuf)
{
  int		i;
  char		*path;
  int		ret;

  i = 0;
  path = NULL;
  if ((ret = glob("*", GLOB_MARK , NULL, globuf)) < 0)
    return (-1);
  while (stock && stock->path && stock->path[i])
    {
      path = my_strslashcat(stock->path[i++], "*");
      if ((ret = glob(my_strdup(path), GLOB_MARK | GLOB_ERR
		      | GLOB_APPEND, NULL, globuf)) == -1)
	return (my_glob_return(globuf, path, -1));
    }
  globuf->gl_pathc = epur_duplicates(globuf->gl_pathv);
  if (globuf->gl_pathc > 50)
    return (disclaimer(globuf, stock, NULL));
  else
    aff_glob(globuf);
  prompt(stock);
  return (my_glob_return(globuf, path, 0));
}

int		one_match(char **send, char *str,
			  glob_t *globuf, t_comp *count)
{
  int		size;
  char		*dup;

  dup = NULL;
  size = my_strlen(str);
  str = my_strdup(globuf->gl_pathv[0]);
  (*send)[my_strlen(*send) - size] = 0;
  *send = my_strcat((*send), str);
  dup = my_strdup(*send);
  while (count->compt > 0)
    {
      if (char_del(send, 48, count, NULL) == -1)
	return (my_glob_return(globuf, dup, -1));
    }
  *send = my_strdup(dup);
  my_putstr(*send);
  count->compt = my_strlen(*send);
  count->save = my_strlen(*send);
  return (my_glob_return(globuf, dup, -1));
}
