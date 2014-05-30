/*
** echo2.c for echo in /home/tawfik_e/Mount/tawfik_e/rendu/42sh
** 
** Made by tawfik
** Login   <tawfik_e@epitech.net>
** 
** Started on  Thu Apr 24 19:35:53 2014 tawfik
** Last update Sat May  3 16:18:05 2014 le-bor_d
*/

#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "builtins.h"

void	echo_help(void)
{
  my_putstr("Usage: /usr/bin/echo [SHORT-OPTION]... [STRING]...\n");
  my_putstr("or:  /usr/bin/echo LONG-OPTION\n");
  my_putstr("Echo the STRING(s) to standard output.\n\n");
  my_putstr("\t-n\t\tdo not output the trailing newline\n");
  my_putstr("\t-e\t\tenable interpretation of backslash escapes\n");
  my_putstr("\t-E\t\tdisable interpretation of backslash escapes(auto)\n\n");
  my_putstr("If -e is in effect, the following sequences are recognized:\n");
  my_putstr("\t\\\\\tbackslash\n");
  my_putstr("\t\\a\talert(BEL)\n");
  my_putstr("\t\\b\tbackspace\n");
  my_putstr("\t\\c\tproduce no further output\n");
  my_putstr("\t\\e\tescape\n");
  my_putstr("\t\\f\tform feed\n");
  my_putstr("\t\\n\tnew line\n");
  my_putstr("\t\\r\tcarriage return\n");
  my_putstr("\t\\t\thorizontal tab\n");
  my_putstr("\t\\v\tvertical tab\n");
  my_putstr("\t\\0NNN\tbyte with octal value NNN (1 to 3 digits)\n");
  my_putstr("\t\\xHH\tbyte with hexadecimal value HH (1 to 2 digits)\n");
  my_putstr("NOTE: your shell may have its own version of echo, ");
  my_putstr("which usually");
  my_putstr(" supersedes the version described here.  Please refer to your ");
  my_putstr("shell's documentation for details about the options it ");
  my_putstr("supports.\n");
}

int	echo_unique(char *str)
{
  if (my_strcmp(str, "--version") == 0)
    {
      my_putstr("echo (sm23dubronx) 1.0\n");
      my_putstr("Written by TAWFIK Emile and his bitches\n");
    }
  else if (my_strcmp(str, "--help") == 0)
    echo_help();
  else
    return (42);
  return (0);
}

int	incorrect_param(char *str)
{
  int	i;

  i = 1;
  if (str[0] != '-')
    return (1);
  while (str && str[i])
    {
      if (str[i] != 'e' && str[i] != 'E' && str[i] != 'n')
	return (1);
      ++i;
    }
  return (0);
}
