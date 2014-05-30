/*
** date_funct.c for prompt in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Sun May  4 17:54:00 2014 le-bor_d
** Last update Sat May 24 14:53:54 2014 le-bor_d
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "prompt.h"

static const char	g_months[][18] =
  {
    {"Jan"},
    {"Feb"},
    {"Mar"},
    {"Apr"},
    {"May"},
    {"Jun"},
    {"Jul"},
    {"Aug"},
    {"Sep"},
    {"Oct"},
    {"Nov"},
    {"Dec"}
  };

static const char	g_days[][18] =
  {
    {"Sun"},
    {"Mon"},
    {"Tue"},
    {"Wed"},
    {"Thu"},
    {"Fri"},
    {"Sat"},
    {"Sun"}
  };

void			d_flag(t_tab *tab, char *prompt,
			       struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  if (printf("%s %s ", g_days[c_time_t->tm_wday],
	     g_months[c_time_t->tm_mon]) < 0)
    (void)write(2, "Printf failed\n", 14);
  if (c_time_t->tm_mday <= 9)
    {
      if (printf("0%d", c_time_t->tm_mday) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d", c_time_t->tm_mday) < 0)
      (void)write(2, "Printf failed\n", 14);
}

void			t_flag(t_tab *tab, char *prompt,
			       struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  t_flag2(c_time_t);
}

void			capital_t_flag(t_tab *tab,
				       char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  if (c_time_t->tm_hour > 12)
    c_time_t->tm_hour -= 12;
  capital_t_flag2(c_time_t);
}

void			at_flag(t_tab *tab, char *prompt,
				struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  if (c_time_t->tm_hour > 12)
    {
      c_time_t->tm_hour -= 12;
      at_flag1(c_time_t);
    }
  else
    at_flag2(c_time_t);
}

void			a_flag(t_tab *tab, char *prompt,
			       struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  if (c_time_t->tm_hour <= 9 && c_time_t->tm_min <= 9)
    {
      if (printf("0%d:0%d", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_min <= 9)
    {
      if (printf("%d:0%d", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_hour <= 9)
    {
      if (printf("0%d:%d", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:%d", c_time_t->tm_hour, c_time_t->tm_min) < 0)
      (void)write(2, "Printf failed\n", 14);
}
