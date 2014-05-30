/*
** fill_file.c for fill_file in /home/abollo_h/rendu/PSU_2013_minishell2/srcs/pipe_and_red
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Sun Feb  9 13:45:38 2014 
** Last update Fri Apr 25 13:47:40 2014 le-bor_d
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my_getline.h"

void	fill_file(int fd1, int fd2)
{
  char	*buff;

  while (buff = get_next_line(fd1))
    {
      write(fd2, buff, my_strlen(buff));
      write(fd2, "\n", 1);
      free(buff);
    }
}
