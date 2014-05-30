/*
** parse_line.c for parse_line in /home/abollo_h/rendu/PSU_2013_minishell2/srcs
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Mon Mar  3 13:38:55 2014
** Last update Sun May 25 19:50:14 2014 TAWFIK
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_getline.h"
#include "backquote.h"
#include "basic_funct.h"
#include "main_funct.h"
#include "structs.h"

static const char	*g_all[] = {
  "<<", "<", "2>>", ">>",
  "2>&1", "2>", ">", ";",
  "||", "&&", "|", "&",
  "(", ")", NULL
};

char			*parse_line(char *str, int i, int n)
{
  int			bool;
  char			*stock;
  char			c;

  bool = 0;
  stock = NULL;
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      is_sentence(str, &bool, i, &c);
      while ((str[i] == ' ') && (str[i + 1] == ' ')
	     && (bool == 0))
	i++;
      if (!str[i + 1] && str[i] == ' ')
	return (stock);
      if ((stock = my_add_char(stock, str[i], ++n)) == NULL)
	return (NULL);
      i++;
    }
  free(str);
  return (stock);
}

char			*add_space(char *str, int i, int n)
{
  int			c1;
  int			c2;
  int			c3;
  char			*tmp;

  c1 = 0;
  c3 = 0;
  c2 = -1;
  if (((i == 0) && (str[i + my_strlen(g_all[n])] == ' ')) ||
      ((i != 0) && (str[i - 1] == 32) && (str[i + my_strlen(g_all[n])] == ' ')))
    return (str);
  if ((tmp = my_xmalloc((my_strlen(str) + 3) * sizeof(char))) == NULL)
    return (NULL);
  while (c1 != i)
    tmp[c1++] = str[c3++];
  if (i != 0)
    tmp[c1++] = ' ';
  while ((str[c3]) && (++c2 != my_strlen(g_all[n])))
    tmp[c1++] = str[c3++];
  tmp[c1++] = ' ';
  while (str[c3])
    tmp[c1++] = str[c3++];
  tmp[c1] = 0;
  free(str);
  return (tmp);
}

int			free_blank(t_list **list)
{
  t_list		*tmp1;
  t_list		*tmp2;

  tmp1 = (*list)->prev;
  tmp2 = (*list);
  if ((*list)->data)
    if (!(*list)->data[0])
      return (-1);
  while ((*list) != tmp1 && (*list)->data)
    {
      if ((*list)->data[0] == 0)
	{
	  free_elem(list);
	  (*list) = (*list)->next;
	}
      else
	(*list) = (*list)->next;
    }
  (*list) = tmp2;
  return (0);
}

char			*free_str(char **str)
{
  free(*str);
  str = NULL;
  mismatch_thing(NULL, 2);
  return (NULL);
}

char			*seperate(char *str, int i, int bool, t_tab *tab)
{
  int			n;
  char			c;

  n = -1;
  c = 0;
  while (str && str[i])
    {
      while ((str[i] == '`') && (is_backslash(str, i)))
	if (find_backquote(&str, tab, i) == -1)
	  return (NULL);
      is_sentence(str, &bool, i, &c);
      while (g_all[++n] && (bool != 1) && (is_backslash(str, i)))
	if (my_strncmp(g_all[n], &str[i], my_strlen(g_all[n])) == 0)
	  {
	    str = add_space(str, i, n);
	    i += my_strlen(g_all[n]) + 1;
	    is_sentence(str, &bool, i, &c);
	    n = -1;
	  }
      n = -1;
      if (str[i])
	++i;
    }
  str = (bool == 1) ? free_str(&str) : (str);
  return (str);
}
