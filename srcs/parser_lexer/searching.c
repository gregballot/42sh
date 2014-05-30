/*
** searching.c for searching in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Feb 11 11:40:26 2014 
** Last update Sat May  3 16:38:33 2014 le-bor_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic_funct.h"
#include "parser.h"

int			search(char *str, int op, int value)
{
  int			i;
  static const char	*search[6][6] =
    {{";", "&&", "||", NULL},
     {"<<", "<", NULL},
     {"2>>", ">>", "2>&1", "2>", ">", NULL},
     {"|", NULL},
     {"(", ")", NULL},
     {"&", NULL}};

  i = -1;
  if (value)
    return (-1);
  while (search[op][++i])
    if (my_strcmp(search[op][i], str) == 0)
      return (0);
  return (-1);
}
