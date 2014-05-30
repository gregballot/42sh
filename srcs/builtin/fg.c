/*
** fg.c for dogesh in /home/tawfik_e/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Mon May  5 17:13:37 2014 tawfik
** Last update Sat May 24 19:28:58 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include "jobs.h"
#include "structs.h"
#include "basic_funct.h"
#include "main_funct.h"

extern t_proc	*g_procli;

int		fg_flag(t_tab *a, t_btree **bta)
{
  t_proc	*proc;
  char		**av;
  int		num;
  int		i;

  (void)a;
  av = (*bta)->right->stock;
  num = (av[1]) ? my_getnbr(av[1]) : 0;
  proc = g_procli;
  i = 1;
  if (num == 0)
    while (proc && proc->next != NULL)
      proc = proc->next;
  else
    while (i++ < num && proc != NULL)
      proc = proc->next;
  if (proc == NULL)
    {
      my_putstr_error("dogesh: fg: current: no such job\n");
      return (1);
    }
  return (cont_proc(proc));
}

int		bg_flag(t_tab *a, t_btree **bta)
{
  t_proc	*proc;
  char		**av;
  int		num;
  int		i;

  (void)a;
  av = (*bta)->right->stock;
  num = (av[1]) ? my_getnbr(av[1]) : 0;
  proc = g_procli;
  i = 1;
  if (num == 0)
    while (proc && proc->next != NULL)
      proc = proc->next;
  else
    while (i++ < num && proc != NULL)
      proc = proc->next;
  if (proc == NULL)
    {
      my_putstr_error("dogesh: bg: current: no such job\n");
      return (1);
    }
  return (cont_back_proc(proc));
}
