/*
** lexer_fonc.c for lexer_fonc in /home/abollo_h/minishell1/PSU_2013_minishell2/srcs/parser_lexer
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Feb 11 20:16:31 2014 
** Last update Fri May 23 16:36:47 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "basic_funct.h"
#include "main_funct.h"

int	lex_pipe(t_list **list)
{
  if ((search((*list)->next->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->prev->data, PIPE, (*list)->quote) != -1) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (my_strcmp((*list)->prev->data, "(") == 0) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->prev->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      ((*list)->next->data == NULL) ||
      ((*list)->prev->data == NULL))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

int	lex_red_l(t_list **list)
{
  if ((my_strcmp((*list)->next->data, "(") == 0) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (search((*list)->next->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->next->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, PIPE, (*list)->quote) != -1) ||
      ((*list)->next->data == NULL) ||
      ((*list)->next->data == NULL))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

int	lex_orand(t_list **list)
{
  if ((search((*list)->prev->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->next->data, PIPE, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (my_strcmp((*list)->prev->data, "(") == 0) ||
      ((*list)->next->data == NULL) ||
      ((*list)->prev->data == NULL))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}

int	lex_par(t_list **list)
{
  if (my_strcmp((*list)->data, "(") == 0)
    {
      if ((my_strcmp((*list)->next->data, ")") == 0) ||
	  (my_strcmp((*list)->prev->data, ")") == 0) ||
	  (my_strcmp((*list)->next->data, "|") == 0) ||
	  (my_strcmp((*list)->next->data, ";") == 0) ||
	  ((*list)->next->data == NULL))
	{
	  my_puterror((*list)->data, 4);
	  return (-1);
	}
    }
  else
    {
      if ((my_strcmp((*list)->next->data, "(") == 0) ||
	  (my_strcmp((*list)->prev->data, "(") == 0) ||
	  (my_strcmp((*list)->prev->data, "|") == 0) ||
	  (my_strcmp((*list)->prev->data, ";") == 0) ||
	  ((*list)->prev->data == NULL))
	{
	  my_puterror((*list)->data, 4);
	  return (-1);
	}
    }
  return (0);
}

int	lex_scolon(t_list **list)
{
  if (my_strcmp((*list)->data, ";") != 0)
    return (lex_orand(list));
  if ((my_strcmp((*list)->prev->data, "(") == 0) ||
      ((*list)->prev->data == NULL) ||
      (search((*list)->prev->data, RED_L, (*list)->quote) != -1) ||
      (search((*list)->prev->data, RED_R, (*list)->quote) != -1) ||
      (search((*list)->next->data, SEP, (*list)->quote) != -1) ||
      (search((*list)->prev->data, SEP, (*list)->quote) != -1) ||
      (my_strcmp((*list)->prev->data, "|") == 0) ||
      (my_strcmp((*list)->next->data, ")") == 0) ||
      (my_strcmp((*list)->next->data, "|") == 0))
    {
      my_puterror((*list)->data, 4);
      return (-1);
    }
  return (0);
}
