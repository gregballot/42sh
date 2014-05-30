/*
** load_file.c for  in /home/ballot_g/rendu/42sh/srcs/conf
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Wed Apr 23 11:49:09 2014 Gregoire Ballot
** Last update Sun May 25 15:16:59 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "basic_funct.h"
#include "structs.h"
#include "my_getline.h"
#include "main_funct.h"

int		load_conf_file(t_tab *tab, char *path)
{
  int		fd;
  int		size;

  size = my_strlen(path) - 1;
  while (size >= 0 &&  path[size] != '/')
    --size;
  if (path)
    path[size + 1] = '\0';
  if ((path = my_strcat(path, my_strdup("dogeshrc"))) == NULL)
    return (-1);
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      write(2, "Can't load dogeshrc\n", 20);
      return (-1);
    }
  while ((tab->buff = get_next_line(fd)) != NULL)
    {
      if (tab->buff[0] != '#')
	if (only_space(tab) != -1)
	  if ((tab->buff[0] >= 32) && (tab->buff[0] <= 126))
	    exec_all(tab, my_strdup(tab->buff));
      free(tab->buff);
      tab->buff = NULL;
    }
  return (0);
}
