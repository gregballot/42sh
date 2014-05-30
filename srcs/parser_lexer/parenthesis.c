/*
** parenthesis.c for parenthesis in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Feb 12 13:16:19 2014 
** Last update Sat May 24 16:22:57 2014 
*/

#include <stdlib.h>
#include "structs.h"
#include "basic_funct.h"
#include "parser.h"
#include "main_funct.h"

int	count_par(t_list **list)
{
  int	left;
  int	right;

  left = 0;
  right = 0;
  to_start(list, 0);
  while ((*list)->data)
    {
      if (my_strcmp((*list)->data, "(") == 0)
	left++;
      if (my_strcmp((*list)->data, ")") == 0)
	right++;
      *list = (*list)->next;
    }
  to_start(list, 0);
  if (right != left)
    {
      mismatch_thing(NULL, 1);
      return (-1);
    }
  return (0);
}
