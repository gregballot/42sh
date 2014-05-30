/*
** other_char.c for ohter_char in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Wed Jan  1 11:52:07 2014 
** Last update Sun May 18 15:39:31 2014 
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"
#include "prompt.h"

int	char_neg(char **send, unsigned long int buff,
		 t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)stock;
  while (count->compt != 0)
    {
      --count->compt;
      --count->save;
      *send = del_letter(*send, buff, count);
      cp = tgetstr("LE", NULL);
      s1 = tgoto(cp, 0, 1);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
      cp = tgetstr("dc", NULL);
      s1 = tgoto(cp, 0, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int	char_ctr_a(char **send, unsigned long int buff,
		   t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  (void)send;
  (void)stock;
  while (count->compt != 0)
    {
      --count->compt;
      cp = tgetstr("LE", NULL);
      s1 = tgoto(cp, 0, 1);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int	char_ctr_c(char **send, unsigned long int buff,
		   t_comp *count, t_tab *stock)
{
  (void)buff;
  my_putstr("EOT\n");
  free(*send);
  *send = NULL;
  prompt(stock);
  count->compt = 0;
  count->save = 0;
  return (0);
}

int	char_ctr_e(char **send, unsigned long int buff,
		   t_comp *count, t_tab *stock)
{
  char	*cp;
  char	*s1;

  (void)buff;
  (void)stock;
  (void)send;
  while (count->compt != count->save)
    {
      count->compt++;
      cp = tgetstr("RI", NULL);
      s1 = tgoto(cp, 1, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int	char_ctr_g(char **send, unsigned long int buff,
		   t_comp *count, t_tab *stock)
{
  (void)buff;
  (void)stock;
  (void)send;
  (void)count;
  my_putstr("\a");
  return (0);
}
