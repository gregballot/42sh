/*
** other_char_b.c for other_char_b.c in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Thu Jan  2 11:12:00 2014
** Last update Sat May 24 13:28:40 2014 Gregoire Ballot
*/

#include <curses.h>
#include <term.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"

static int	is_alphanum(char c)
{
  if ((c >= 'A') && (c <= 'Z'))
    return (0);
  if ((c >= 'a') && (c <= 'z'))
    return (0);
  if ((c >= '0') && (c <= '9'))
    return (0);
  if (c == ' ')
    return (2);
  return (-1);
}

int		paste(char **send, unsigned long int buff,
		      t_comp *count, t_tab *stock)
{
  if ((buff == '\n') || (buff == 10))
    return (1);
  if (buff == 0)
    return (0);
  if ((buff % 256 >= 32) && (buff % 256 <= 126))
    char_letter(send, buff % 256, count, stock);
  if (paste(send, buff / 256, count, stock) == 1)
    return (1);
  return (0);
}

int		ctrl_term_left(char **send, unsigned long int buff,
			       t_comp *count, t_tab *stock)
{
  int		i;

  (void)buff;
  (void)stock;
  if (count->compt != 0)
    {
      i = is_alphanum((*send)[count->compt - 1]);
      while ((i == is_alphanum((*send)[count->compt - 1]))
	     && (count->compt))
	term_left(send, buff, count, stock);
    }
  return (0);
}

int		ctrl_term_right(char **send, unsigned long int buff,
				t_comp *count, t_tab *stock)
{
  int		i;

  (void)buff;
  (void)stock;
  if (count->compt != count->save)
    {
      i = is_alphanum((*send)[count->compt]);
      while ((i == is_alphanum((*send)[count->compt]))
	     && (count->compt != count->save))
	term_right(send, buff, count, stock);
    }
  return (0);
}

int		char_ctr_k(char **send, unsigned long int buff,
			   t_comp *count, t_tab *stock)
{
  char		*cp;
  char		*s1;
  int		i;

  (void)stock;
  i = count->compt;
  while (count->compt != count->save)
    {
      count->compt++;
      cp = tgetstr("RI", NULL);
      my_tputs(tgoto(cp, 1, 0), 0, my_putchar);
    }
  count->compt = count->save;
  while (count->compt != i)
    {
      --count->compt;
      --count->save;
      *send = del_letter(*send, buff, count);
      cp = tgetstr("LE", NULL);
      my_tputs(tgoto(cp, 1, 0), 0, my_putchar);
      cp = tgetstr("dc", NULL);
      s1 = tgoto(cp, 0, 0);
      my_tputs(s1, 0, my_putchar);
    }
  return (0);
}
