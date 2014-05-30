/*
** name_funct.c for prompt in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Sun May  4 13:54:21 2014 le-bor_d
** Last update Sat May 24 14:25:45 2014 le-bor_d
*/

#include <stdio.h>
#include <unistd.h>
#include "structs.h"
#include "prompt.h"
#include "basic_funct.h"

void		name_flag(t_tab *tab, char *prompt,
			  struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  if (printf("dogesh") < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		user_flag(t_tab *tab, char *prompt,
			  struct tm *c_time_t, int p)
{
  char		*name;

  (void)prompt;
  (void)p;
  (void)c_time_t;
  if ((name = my_getenv(tab->env, "USER=")) != NULL)
    if (printf("%s", name) < 0)
    (void)write(2, "Printf failed\n", 14);
}
