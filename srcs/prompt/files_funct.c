/*
** files_funct.c for prompt in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Sun May  4 14:06:22 2014 le-bor_d
** Last update Sat May 24 13:36:42 2014 Gregoire Ballot
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "prompt.h"
#include "basic_funct.h"

static void	find_tild(char *buff, char *home)
{
  int		i;
  int		j;

  i = 0;
  while (buff[i] != 0 && buff[i] == home[i])
    ++i;
  j = 1;
  buff[0] = '~';
  while (buff[i] != '\0')
    buff[j++] = buff[i++];
  buff[j] = 0;
  if (printf("%s", buff) < 0)
    (void)write(2, "Printf failed\n", 14);
}

void		w_flag(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  char		*buff;
  char		*home;

  (void)prompt;
  (void)p;
  (void)c_time_t;
  if ((buff = my_getenv(tab->env, "PWD=")) == NULL)
    return ;
  if ((home = my_getenv(tab->env, "HOME=")) == NULL
      || my_strncmp(buff, home, my_strlen(home)) != 0)
    {
      if (printf("%s", buff) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    find_tild(buff, home);
}

void		capital_w_flag(t_tab *tab, char *prompt,
			       struct tm *c_time_t, int p)
{
  char		*buff;
  int		i;

  (void)prompt;
  (void)p;
  (void)c_time_t;
  if ((buff = my_getenv(tab->env, "PWD=")) == NULL)
    {
      if (printf("NULL") < 0)
	(void)write(2, "Printf failed\n", 14);
      return ;
    }
  i = my_strlen(buff);
  while (--i >= 0 && buff[i] != '/')
    ;
  if (printf("%s", &buff[i]) < 0)
    (void)write(2, "Printf failed\n", 14);
}
