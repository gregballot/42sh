/*
** my_getnbr_base.c for day07 in /home/tawfik_e/rendu/Piscine-C-Jour_06/ex_16
** 
** Made by tawfik
** Login   <tawfik_e@epitech.net>
** 
** Started on  Tue Oct  8 18:40:47 2013 tawfik
** Last update Thu May  8 11:54:37 2014 le-bor_d
*/

#include "basic_funct.h"

static int	my_where_is(const char c, const char *s)
{
  int		i;
  int		v;

  i = 0;
  v = 0;
  while (s[i] && v == 0)
    {
      if (c == s[i])
	v = 1;
      i = i + 1;
    }
  if (v == 1)
    return (i - 1);
  else
    return (-1);
}

int		my_getnbr_base(const char *str, const char *base, int nb)
{
  int		ret;
  int		i;

  ret = 0;
  i = 0;
  while (str && str[i] && i < nb)
    {
      ret *= my_strlen(base);
      ret += my_where_is(str[i], base);
      ++i;
    }
  return (ret);
}

int		my_putnbr(int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (0);
}
