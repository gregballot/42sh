/*
** echo.c for echo in /home/tawfik_e/Mount/tawfik_e/rendu/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Thu Apr 24 14:00:06 2014 tawfik
** Last update Sun May 25 14:47:25 2014 TAWFIK
*/

#include <stdlib.h>
#include "basic_funct.h"
#include "structs.h"
#include "my_getline.h"
#include "builtins.h"

static const char	g_spechar[][2] =
  {
    {'\\', '\\'},
    {'a', '\a'},
    {'b', '\b'},
    {'e', '\e'},
    {'f', '\f'},
    {'n', '\n'},
    {'r', '\r'},
    {'t', '\t'},
    {'v', '\v'},
    {0, 0}
  };

char		*echo_get_options(int *ac, char **av)
{
  char		*opt;
  int		i;

  if ((opt = malloc(2)) == NULL)
    return (NULL);
  opt[1] = 'E';
  opt[0] = 0;
  (*ac) = 1;
  while (av[(*ac)] && !incorrect_param(av[(*ac)]))
    {
      i = 1;
      while (av[(*ac)] && av[(*ac)][i])
	{
	  if ('e' == av[(*ac)][i])
	    opt[1] = 'e';
	  if ('E' == av[(*ac)][i])
	    opt[1] = 'E';
	  if ('n' == av[(*ac)][i])
	    opt[0] = 'n';
	  ++i;
	}
      ++(*ac);
    }
  return (opt);
}

void		my_putchar_echo2(char *str, int *i)
{
  int		tmp;

  if (str[(*i)] == 'x')
    {
      ++(*i);
      tmp = my_getnbr_base(&(str[(*i)]), "0123456789ABCDEF", 2);
      my_putchar((char)tmp);
      if (str[(*i)])
	++(*i);
    }
  else if (str[(*i)] == '0')
    {
      ++(*i);
      tmp = my_getnbr_base(&(str[(*i)]), "01234567", 3);
      my_putchar((char)tmp);
      if (str[(*i)])
	++(*i);
      if (str[(*i)])
	++(*i);
    }
  else
    {
      my_putchar('\\');
      my_putchar(str[(*i)]);
    }
}

void		my_putchar_echo(char *str, int *i)
{
  int		idx;

  idx = 0;
  while (g_spechar[idx][READ] && str[(*i)] != g_spechar[idx][READ])
    ++idx;
  if (g_spechar[idx][READ] != 0)
    my_putchar(g_spechar[idx][WRITE]);
  else
    my_putchar_echo2(str, i);
}

int		my_put_echo(char *str, char opt)
{
  int		i;

  i = 0;
  if (opt == 'e')
    {
      while (str && str[i])
	{
	  if (str[i] == '\\')
	    {
	      ++i;
	      if (str[i] == 'c')
		return (-1);
	      my_putchar_echo(str, &i);
	    }
	  else
	    my_putchar(str[i]);
	  if (str[i])
	    ++i;
	}
    }
  else
    my_putstr(str);
  return (0);
}

int		echo_flag(t_tab *a, t_btree **bta)
{
  char		**stock;
  char		*opt;
  int		ac;
  int		sav;

  (void)a;
  stock = (*bta)->right->stock;
  ac = 0;
  while (stock[ac])
    ++ac;
  if (ac == 2 && (echo_unique(stock[1]) == 0))
    return (0);
  if ((opt = echo_get_options(&ac, stock)) == NULL)
    return (-1);
  sav = ac;
  while (stock[ac])
    {
      if (sav != ac)
	my_putchar(' ');
      if (my_put_echo(stock[ac++], opt[1]) == -1)
	return (0);
    }
  if (opt[0] == 0)
    my_putchar('\n');
  return (0);
}
