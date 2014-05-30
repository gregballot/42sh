/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/abollo_h/rendu/Piscine-C-Jour_08/ex_04
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Fri Oct 11 08:58:10 2013
** Last update Wed May 21 10:47:35 2014 Gregoire Ballot
*/

#include <stdlib.h>
#include "basic_funct.h"

int		my_wordtab_len(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    while (tab[i])
      ++i;
  return (i);
}

static char	**char_in_str(char *str, int c, char **tab, char s)
{
  int		x;
  int		i;

  x = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] != s)
	tab[c][x++] = str[i];
      i = i + 1;
      if ((str[i] == s) && (str[i + 1] != s))
	{
	  tab[c++][x] = 0;
	  x = 0;
	}
      if ((str[i] == 0) && (str[i - 1] != s))
	{
	  tab[c++][x] = 0;
	  x = 0;
	}
    }
  return (tab);
}

static int	str_in_tab(char *str, int c, char **tab, char s)
{
  int		n;
  int		i;

  n = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] != s)
	n = n + 1;
      if ((str[i] == s) && (str[i + 1] != s))
	{
	  if ((tab[c++] = my_xmalloc((n + 1) * sizeof(char))) == NULL)
	    return (-1);
	  n = 0;
	}
      i = i + 1;
    }
  if ((str[i] == 0) && (str[i - 1] != s))
    {
      if ((tab[c++] = my_xmalloc((n + 1) * sizeof(char))) == NULL)
	return (-1);
      n = 0;
    }
  return (0);
}

static int	parsing(char *str, int i, char s)
{
  int		nbr;

  nbr = 1;
  while (str[i])
    {
      if ((str[i] == s) && (str[i + 1] != s))
	if (str[i + 1])
	nbr = nbr + 1;
      i = i + 1;
    }
  return (nbr);
}

char		**my_wordtab(char *str, char s)
{
  char		**tab;
  int		n;

  if (!str || !str[0])
    return (NULL);
  n = parsing(str, 0, s);
  if ((tab = my_xmalloc((n + 1) * sizeof(char *))) == NULL)
    return (NULL);
  tab[n] = NULL;
  if (str_in_tab(str, 0, tab, s) == -1)
    return (NULL);
  return (char_in_str(str, 0, tab, s));
}
