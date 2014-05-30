/*
** termcaps.c for  in /home/locate_a/rendu/42sh/final/42sh
**
** Made by a
** Login   <locate_a@epitech.net>
**
** Started on  Fri May  9 18:51:52 2014 a
** Last update Sun May 25 22:38:23 2014 
*/

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include "termcaps.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"
#include "prompt.h"

static const t_term	g_termio[] =
  {
    {10, &char_nl},
    {12, &char_cl},
    {21, &char_neg},
    {27, &char_move},
    {127, &char_del},
    {16, &term_up},
    {1, &char_ctr_a},
    {2, &term_left},
    {3, &char_ctr_c},
    {5, &char_ctr_e},
    {6, &term_right},
    {7, char_ctr_g},
    {8, &char_del},
    {11, &char_ctr_k},
    {13, &char_cl},
    {14, &char_cl},
    {23, &char_neg},
    {9, &auto_complete},
    {4283163, &term_up},
    {4348699, &term_down},
    {4414235, &term_right},
    {4479771, &term_left},
    {74995417045787, &ctrl_term_left},
    {73895905418011, &ctrl_term_right},
    {-1, &char_letter}
  };

int			loop(char **send, unsigned long int *buff,
			     t_tab *stock, t_comp *count)
{
  while (count->n < sizeof(g_termio) / sizeof(g_termio[0]))
    {
      if (*buff == g_termio[count->n].nbr)
	{
	  if (g_termio[count->n].ptr(send, *buff, count, stock) == 1)
	    return (0);
	  count->n = sizeof(g_termio) / sizeof(g_termio[0]);
	  *buff = 0;
	}
      else if ((count->n == (sizeof(g_termio) / sizeof(g_termio[0])) - 1)
	       && (*buff >= 32) && (*buff <= 125))
	{
	  g_termio[count->n].ptr(send, *buff, count, stock);
	  *buff = 0;
	}
      count->n++;
    }
  return (0);
}

int			character(char **send, unsigned long int buff,
				  t_tab *stock)
{
  t_comp		count;

  count.save = 0;
  count.compt = 0;
  while ((read(0, &buff, 8) > 0) && (buff != 4))
    {
      count.n = 0;
      if ((buff == '\n') || (buff == 10))
	{
	  if (*send == NULL)
	    char_nl(send, buff, &count, stock);
	  return (0);
	}
      loop(send, &buff, stock, &count);
      if (buff != 0)
	if (paste(send, buff, &count, stock) == 1)
	  return (0);
      buff = 0;
    }
  return (-1);
}

int			termcaps(char **send, t_tab *stock)
{
  struct termios	t;
  char			*cp;
  int			ret;

  ret = 0;
  prompt(stock);
  tcgetattr(0, &t);
  t.c_lflag &= ~(ECHO | ICANON);
  t.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &t);
  cp = tgetstr("im", NULL);
  if (my_tputs(cp, 0, my_putchar) == -1)
    ret = -1;
  if (ret != -1)
    ret = character(send, 0, stock);
  cp = tgetstr("ei", NULL);
  if (my_tputs(cp, 0, my_putchar) == -1)
    ret = -1;
  t.c_lflag |= ECHO | ICANON;
  tcsetattr(0, TCSANOW, &t);
  if (ret == -1)
    return (-1);
  return (0);
}

int			my_getentry(t_tab *stock)
{
  if (tgetent(NULL, my_getenv(stock->env, "TERM=")) != 1)
    if (tgetent(NULL, "xterm") == -1)
      {
	prompt(stock);
	return (-1);
      }
  return (0);
}

char			*my_getline(t_tab *stock, int *i)
{
  char			*send;
  int			ret;

  ret = 0;
  if (my_getentry(stock) == -1)
    return (get_next_line(0));
  send = NULL;
  while (ret != -1)
    {
      if (stock)
	stock->move = 0;
      ret = termcaps(&send, stock);
      if (ret != -1)
	{
	  init_list(&(stock->list), send, i);
	  (*i)++;
	  my_putchar(10);
	  return (send);
	}
    }
  if (stock->list)
    free_list(&(stock->list));
  free(send);
  return (NULL);
}
