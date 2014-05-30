/*
** uid_funct.c for prompt in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Sun May  4 13:29:39 2014 le-bor_d
** Last update Sun May 25 12:27:00 2014 a
*/

#include <stdio.h>
#include <unistd.h>
#include "structs.h"
#include "prompt.h"
#include "basic_funct.h"

void		sharp_flag(t_tab *tab, char *prompt,
			   struct tm *c_time_t, int p)
{
  (void)c_time_t;
  (void)prompt;
  (void)p;
  if (printf("%d", tab->count) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		dollar_flag(t_tab *tab, char *prompt,
			    struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)c_time_t;
  (void)p;
  if (printf("%d", getuid()) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		v_flag(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)c_time_t;
  (void)prompt;
  (void)p;
  if (printf("%s", VERSION) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		capital_v_flag(t_tab *tab, char *prompt,
			       struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)c_time_t;
  (void)p;
  if (printf("%s", VERSION_2) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		h_flag(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  char		*buff;

  (void)c_time_t;
  (void)prompt;
  (void)p;
  if ((buff = my_getenv(tab->env, "HOSTNAME=")) == NULL)
    return ;
  if (printf("%s", buff) < 0)
    (void)write(2, "Printf failed\n", 14);
}
