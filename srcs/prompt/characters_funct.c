/*
** characters_funct.c for prompt in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Sun May  4 15:35:52 2014 le-bor_d
** Last update Thu May 22 10:53:42 2014 le-bor_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs.h"
#include "prompt.h"
#include "basic_funct.h"

void	backslash_n(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  if (printf("\n") < 0)
    (void)write(2, "Printf failed\n", 14);
}

void	backslash_a(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  if (printf("\a") < 0)
    (void)write(2, "Printf failed\n", 14);
}

void	backslash_r(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  if (printf("\r") < 0)
    (void)write(2, "Printf failed\n", 14);
}

void	backslash_slash(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  (void)tab;
  (void)prompt;
  (void)p;
  (void)c_time_t;
  if (printf("\\") < 0)
    (void)write(2, "Printf failed\n", 14);
}

void	backslash_e(t_tab *tab, char *prompt, struct tm *c_time_t, int p)
{
  char	*str;
  int	i;

  (void)tab;
  (void)p;
  (void)c_time_t;
  if ((str = my_strdup(prompt)) == NULL)
    return ;
  i = p;
  while (str[++i] != 0 && my_strncmp(&str[i], "\\]", 2) != 0)
    ;
  str[i] = '\0';
  if (printf("%s", &str[i]) < 0)
    (void)write(2, "Printf failed\n", 14);
  if (printf("\e") < 0)
    (void)write(2, "Printf failed\n", 14);
}
