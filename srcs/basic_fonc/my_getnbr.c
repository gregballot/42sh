/*
** my_getnbr.c for my_getnbr in /home/abollo_h
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Jan 26 13:09:15 2014 
** Last update Sat May 24 22:45:45 2014 Grégoire BALLOT
*/

#include <stdlib.h>

int	my_searchlen(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (!str || !str[i])
    return (0);
  while ((str[j] == '+') || (str[j] == '-'))
    j++;
  while (str[j])
    {
      j++;
      i++;
    }
  return (i);
}

int	my_power_it(int nbr, int pow)
{
  int	i;
  int	cpy;

  i = -1;
  cpy = nbr;
  if (pow == 0)
    return (1);
  if (pow == 1)
    return (nbr);
  while (++i != pow - 1)
    nbr *= cpy;
  return (nbr);
}

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	len_n;
  int	nbr;

  neg = 0;
  if (str == NULL)
    return (0);
  i = 0;
  while ((str[i] == '-') || (str[i] == '+'))
    i++;
  if ((i != 0) && (str[i - 1] = '-'))
    neg = 1;
  nbr = 0;
  len_n = my_searchlen(str);
  while (str[i])
    nbr += (str[i++] - 48) * my_power_it(10, --len_n);
  if (neg == 1)
    return (-nbr);
  else
    return (nbr);
}
