/*
** op_and_sep.c for op_and_sep in /home/abollo_h/rendu/Parser/srcs/parser_lexer
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sat Apr 19 22:30:11 2014
** Last update Sun May 25 19:48:48 2014 TAWFIK
*/

#include "my_getline.h"
#include "parser.h"
#include "basic_funct.h"

int			find_sep(char *stock, int value)
{
  int			i;
  static const char	*tab[] =
    {
      ";", "&&", "||"
    };

  i = -1;
  if (value || !stock)
    return (-1);
  while (++i != sizeof(tab) / sizeof(tab[0]))
    if (!my_strcmp(tab[i], stock))
      return (i);
  return (-1);
}

int			find_op(char *stock, int value)
{
  int			i;
  static const char	*tab[] =
    {
      "2>>", "2>&1", "2>", ">>", ">", "<<", "<"
    };

  i = -1;
  if (value || !stock)
    return (-1);
  while (++i != sizeof(tab) / sizeof(tab[0]))
    if (!my_strcmp(tab[i], stock))
      return (0);
  return (-1);
}
