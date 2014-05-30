/*
** prompt.c for prompt in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Sat May  3 11:53:09 2014 le-bor_d
** Last update Sun May 25 17:25:06 2014 TAWFIK
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "structs.h"
#include "basic_funct.h"
#include "prompt.h"

static const t_prompt	g_prompt[] =
  {
    {"\\d", &d_flag}, {"\\g", &git_flag},
    {"\\r", &backslash_r}, {"\\\\", &backslash_slash},
    {"\\s", &name_flag}, {"\\t", &t_flag},
    {"\\e", &backslash_e}, {"\\h", &h_flag},
    {"\\[", &backslash_no}, {"\\H", &h_flag},
    {"\\]", &backslash_no},
    {"\\n", &backslash_n}, {"\\a", &backslash_a},
    {"\\T", &capital_t_flag}, {"\\@", &at_flag},
    {"\\A", &a_flag}, {"\\u", &user_flag},
    {"\\v", &v_flag}, {"\\V", &capital_v_flag},
    {"\\w", &w_flag}, {"\\W", &capital_w_flag},
    {"\\#", &sharp_flag}, {"\\$", &dollar_flag},
    {NULL, NULL}
  };

static void		write_prompt(struct tm *c_time_t,
				     char *prompt, t_tab *tab)
{
  int			i;
  int			j;

  i = -1;
  while (prompt[++i] != '\0')
    {
      j = 0;
      while (g_prompt[j].str != NULL &&
      	     my_strncmp(g_prompt[j].str, &prompt[i], 2) != 0)
      	++j;
      if (g_prompt[j].str != NULL)
      	{
      	  i += 1;
      	  g_prompt[j].ptr(tab, prompt, c_time_t, i);
      	}
      else
	if (printf("%c", prompt[i]) < 0)
	  (void)write(2, "Printf failed\n", 14);
    }
  fflush(stdout);
}

void			backslash_no(t_tab *tab, char *prompt,
				     struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  return ;
}

void			prompt(t_tab *tab)
{
  time_t		t;
  struct tm		*c_time_t;
  char			*stock;
  char			*prompt;

  check_all_proc();
  if (isatty(0) == 0)
    return ;
  if (time(&t) == (time_t)-1)
    return ;
  if ((c_time_t = localtime(&t)) == NULL)
    return ;
  if ((prompt = my_getenv(tab->env, "PS1=")) != NULL)
    return (write_prompt(c_time_t, prompt, tab));
  if ((prompt = my_getenv(tab->env, "PS2=")) != NULL)
    return (write_prompt(c_time_t, prompt, tab));
  if ((stock = my_getenv(tab->env, "USER=")) != NULL)
    {
      my_putstr("(");
      my_putstr(stock);
      my_putstr(") : ");
      return ;
    }
  my_putstr("?> : ");
}
