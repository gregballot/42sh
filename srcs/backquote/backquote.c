/*
** backquote.c for backquote in /home/abollo_h/rendu/42sh/srcs/main_fonc
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue May  6 13:43:44 2014 
** Last update Sun May 25 16:34:44 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "structs.h"
#include "backquote.h"
#include "basic_funct.h"
#include "main_funct.h"

static void	change_char(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] <= 31)
	str[i] = ' ';
      i++;
    }
}

char		*my_strfreecat(char *s1, char *s2, int is_free)
{
  int		len;
  int		i;
  char		*ptr;

  i = 0;
  len = my_strlen(s1) + my_strlen(s2);
  if ((ptr = my_xmalloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  ptr[len] = 0;
  len = 0;
  while (s1 && s1[i])
    ptr[len++] = s1[i++];
  i = 0;
  while (s2 && s2[i])
    ptr[len++] = s2[i++];
  if (is_free == 1 || is_free == 2)
    free(s2);
  if (is_free == 2 || is_free == 3)
    free(s1);
  return (ptr);
}

static int	replace_quote(char **str, char *replace)
{
  char		*new_string;
  int		n;

  n = 0;
  while (((*str)[n]) && (((*str)[n] != '`') || (!is_backslash(*str, n))))
    n++;
  if ((new_string = my_xmalloc((n + 1) * sizeof(char))) == NULL)
    return (-1);
  new_string[n] = 0;
  n = 0;
  while (((*str)[n]) && (((*str)[n] != '`') || (!is_backslash(*str, n))))
    {
      new_string[n] = (*str)[n];
      n++;
    }
  ++n;
  while (((*str)[n]) && (((*str)[n] != '`') || (!is_backslash(*str, n))))
    ++n;
  ++n;
  if (((new_string = my_strfreecat(new_string, replace, 1)) == NULL) ||
      ((new_string = my_strfreecat(new_string, &((*str)[n]), 0)) == NULL))
    return (-1);
  free(*str);
  *str = new_string;
  return (0);
}

static int	fill_str(char **str, t_tab *tab, int i, int len)
{
  char		*s2;
  int		n;

  n = 0;
  tab->stock_pipe = NULL;
  if ((s2 = my_xmalloc((len + 1) * sizeof(char))) == NULL)
    return (-1);
  s2[len] = 0;
  ++i;
  while (((*str)[i]) && (((*str)[i] != '`') || (!is_backslash(*str, i))))
    s2[n++] = (*str)[i++];
  ++tab->bquote;
  exec_all(tab, s2);
  change_char(tab->stock_pipe);
  --tab->bquote;
  return (replace_quote(str, tab->stock_pipe));
}

int		find_backquote(char **str, t_tab *tab, int i)
{
  int		length;
  int		index;
  char		c;

  index = i + 1;
  length = 0;
  c = 0;
  while (((*str)[index]) && (((*str)[index] != '`') ||
			     (!is_backslash(*str, index))))
    {
      if ((*str)[index++] != ' ')
	c = 1;
      ++length;
    }
  if (!(*str)[index] || !isatty(0))
    {
      free(*str);
      *str = NULL;
      mismatch_thing(NULL, 2);
      return (-1);
    }
  if (c == 1)
    return (fill_str(str, tab, i, length));
  return (replace_quote(str, NULL));
}
