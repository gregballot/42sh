/*
** miniterm.c for miniterm in /home/abollo_h/rendu/PSU_2013_my_select/test/termios
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Dec 31 10:53:21 2013 
** Last update Sun May 25 13:13:53 2014 
*/

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"
#include "prompt.h"

int			char_cl(char **send, unsigned long int buff,
				t_comp *count, t_tab *stock)
{
  char			*cp;
  char			*s1;

  (void)buff;
  cp = tgetstr("cl", NULL);
  if (my_tputs(cp, 0, my_putchar) == -1)
    return (-1);
  prompt(stock);
  my_putstr(*send);
  if ((count->save - count->compt) != 0)
    {
      cp = tgetstr("LE", NULL);
      s1 = tgoto(cp, 0, count->save - count->compt);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int			char_nl(char **send, unsigned long int buff,
				t_comp *count, t_tab *stock)
{
  (void)buff;
  (void)count;
  (void)stock;
  if (*send == NULL)
    {
      if ((*send = my_xmalloc(2)) == NULL)
	return (1);
      (*send)[0] = ' ';
      (*send)[1] = 0;
    }
  return (1);
}

int			char_del(char **send, unsigned long int buff,
				 t_comp *count, t_tab *stock)
{
  char			*cp;
  char			*s1;

  (void)stock;
  if (count->compt != 0)
    {
      --count->compt;
      --count->save;
      *send = del_letter(*send, buff, count);
      cp = tgetstr("LE", NULL);
      s1 = tgoto(cp, 1, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
      cp = tgetstr("dc", NULL);
      s1 = tgoto(cp, 0, 0);
      if (my_tputs(s1, 0, my_putchar) == -1)
	return (-1);
    }
  return (0);
}

int			char_letter(char **send, unsigned long int buff,
				    t_comp *count, t_tab *stock)
{
  (void)stock;
  if ((buff >= 32) && (buff <= 256))
    {
      if ((*send = add_letter(*send, buff, count)) == NULL)
	return (-1);
      my_putchar(buff);
      count->save++;
      count->compt++;
    }
  return (0);
}

int			char_move(char **send, unsigned long int buff,
				  t_comp *count, t_tab *stock)
{
  int			i;
  static const t_term	move[] = {{68, &term_left}, {67, &term_right},
			  {65, &term_up}, {66, &term_down}};

  i = 0;
  if (buff == 91)
    {
      read(0, &buff, 1);
      while (i != sizeof(move) / sizeof(move[0]))
	{
	  if (move[i].nbr == buff)
	    {
	      move[i].ptr(send, buff, count, stock);
	      return (0);
	    }
	  i++;
	}
    }
  return (0);
}
