/*
** move.c for termcaps in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Thu May  8 15:24:55 2014 le-bor_d
** Last update Sun May 25 22:39:21 2014 
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"
#include "prompt.h"

int	term_left(char **send, unsigned long int buff,
		  t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  (void)stock;
  (void)send;
  if (count->compt != 0)
    {
      count->compt--;
      cp = tgetstr("LE", NULL);
      s1 = tgoto(cp, 1, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int	term_right(char **send, unsigned long int buff,
		   t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  (void)stock;
  (void)send;
  if (count->compt != count->save)
    {
      count->compt++;
      cp = tgetstr("RI", NULL);
      s1 = tgoto(cp, 1, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int	term_down(char **send, unsigned long int buff,
		t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  if (!stock->list)
    return (0);
  cp = tgetstr("dl", NULL);
  s1 = tgoto(cp, 0, 0);
  if (my_tputs(s1, 0, my_putchar) == -1)
    return (-1);
  cp = tgetstr("ch", NULL);
  s1 = tgoto(cp, 0, 0);
  if (my_tputs(s1, 0, my_putchar) == -1)
    return (-1);
  prompt(stock);
  if (stock->list->prev)
    stock->list = stock->list->prev;
  free(*send);
  my_putstr(stock->list->data);
  *send = my_strdup(stock->list->data);
  count->save = my_strlen(stock->list->data);
  count->compt = count->save;
  return (0);
}

int	term_up(char **send, unsigned long int buff,
		  t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  if (!stock->list)
    return (0);
  cp = tgetstr("dl", NULL);
  s1 = tgoto(cp, 0, 0);
  if (my_tputs(s1, 0, my_putchar) == -1)
    return (-1);
  cp = tgetstr("ch", NULL);
  s1 = tgoto(cp, 0, 0);
  if (my_tputs(s1, 0, my_putchar) == -1)
    return (-1);
  prompt(stock);
  if (stock && stock->move && stock->list->next)
    stock->list = stock->list->next;
  free(*send);
  my_putstr(stock->list->data);
  *send = my_strdup(stock->list->data);
  count->save = my_strlen(stock->list->data);
  count->compt = count->save;
  stock->move = 1;
  return (0);
}
