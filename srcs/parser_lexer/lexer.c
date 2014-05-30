/*
** lexer.c for lexer in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/parser_lexer
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Tue Feb 11 17:16:47 2014
** Last update Sun May 25 19:47:37 2014 TAWFIK
*/

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "main_funct.h"
#include "basic_funct.h"

int			lex_jobs(t_list **list)
{
  if ((my_strcmp((*list)->next->data, "(") == 0) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (my_strcmp((*list)->prev->data, "(") == 0) ||
      (my_strcmp((*list)->prev->data, ")") == 0) ||
      (search((*list)->next->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->prev->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->prev->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->next->data, AND_OR, (*list)->quote) != -1) ||
      (search((*list)->prev->data, AND_OR, (*list)->quote) != -1) ||
      ((*list)->prev->data == NULL))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

int			lex_red_r(t_list **list)
{
  if ((my_strcmp((*list)->next->data, "(") == 0) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (search((*list)->next->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, PIPE, (*list)->quote) != -1) ||
      ((*list)->next->data == NULL) ||
      ((*list)->next->data == NULL))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

int			lex_sent(t_list **list)
{
  if ((my_strcmp((*list)->next->data, "(") == 0) ||
      (my_strcmp((*list)->prev->data, ")") == 0))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

t_list			*add_to_new_stock(t_list **list)
{
  int			n;
  int			i;
  t_list		*new;

  i = -1;
  new = NULL;
  to_start(list, 0);
  while ((*list)->data)
    {
      while (++i < 6)
	if ((n = search((*list)->data, i, (*list)->quote)) != -1)
	    {
	      if (add_op(&new, list) == -1)
		return (NULL);
	      n = 0;
	      i = 7;
	    }
      if (n == -1)
	if (new_stock(&new, list) == -1)
	  return (NULL);
      i = -1;
    }
  return (new);
}

t_list			*lexer(t_list **list)
{
  int			i;
  static const t_lex	lex[] =
    {
      {SEP, &lex_scolon}, {RED_L, &lex_red_l}, {RED_R, &lex_red_r},
      {PIPE, &lex_pipe}, {PAR, &lex_par}, {JOBS, &lex_jobs}
    };

  i = -1;
  while ((*list)->data)
    {
      while (++i < 6)
	if (search((*list)->data, i, (*list)->quote) != -1)
	  {
	    if (lex[i].ptr(list) == -1)
	      return (NULL);
	    i = 7;
	  }
      if (i == 6)
	if ((lex_sent(list)) == -1)
	  return (NULL);
      *list = (*list)->next;
      i = -1;
    }
  return (add_to_new_stock(list));
}
