/*
** my_autcomplete.c for 42 in /home/locate_a/rendu/42sh/final/42sh/srcs/termcaps
**
** Made by a
** Login   <locate_a@epitech.net>
**
** Started on  Mon May  5 04:00:28 2014 a
** Last update Sun May 25 15:01:00 2014 
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

static char	*my_epur_str(char *str)
{
  char		*epur;
  int		i;
  int		j;

  if ((epur = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != '\0')
    {
      while ((str[i] == ' ' || str[i] == '\t')
	  && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
	++i;
      if (str[i] == '\t')
	epur[j++] = ' ';
      else
	epur[j++] = str[i++];
    }
  epur[j] = 0;
  free(str);
  return (epur);
}

int		my_glob_return(glob_t *globbuf, char *path, int ret)
{
  free(path);
  globfree(globbuf);
  return (ret);
}

int		my_tablen(char **tabl)
{
  int		i;

  i = 0;
  if (!tabl)
    return (0);
  while (tabl[i] != NULL)
    ++i;
  return (i - 1);
}

static int	is_last(char *str, char token)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  if (str[i - 1] == token)
    return (1);
  return (0);
}

int		auto_complete(char **send, unsigned long int buff,
			      t_comp *count, t_tab *stock)
{
  glob_t	globbuf;
  char		**cmd;

  (void)buff;
  cmd = NULL;
  if (isatty(0) == 0)
    return (-1);
  if ((*send) == NULL)
    return (every_glob(stock, &globbuf));
  if (is_last((*send), ' ') == 1)
    return (glob_here(&globbuf, send, stock));
  *send = my_epur_str(*send);
  if ((cmd = my_wordtab((*send), ' ')) == NULL)
    return (-1);
  if (my_tablen(cmd) >= 1 || my_strncmp(*send, "./", 2) == 0)
    return (arg_complete(send, stock, count, &globbuf));
  else
    return (bin_completion(send, stock, &globbuf, count));
  return (0);
}
