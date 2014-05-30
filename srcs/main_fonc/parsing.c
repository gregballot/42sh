/*
** parsing.c for parsing in /home/abollo_h/rendu/PSU_2013_minishell1/minishell
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Wed Dec 18 08:16:22 2013
** Last update Wed May 21 12:06:50 2014 Gregoire Ballot
*/

#include <stdlib.h>
#include "my_getline.h"
#include "basic_funct.h"
#include "structs.h"
#include "main_funct.h"

int	epur_str(char **buff, int n, int i, char ***save)
{
  int	k;
  int	j;

  free(*buff);
  if ((*buff = my_xmalloc((k = n + 1) * sizeof(char))) == NULL)
    return (-1);
  (*buff)[k - 1] = 0;
  n = -1;
  j = 0;
  while (++n != k - 1)
    {
      if ((*save)[i][j] == 0)
	{
	  (*buff)[n++] = ' ';
	  j = 0;
	  i++;
	}
      (*buff)[n] = (*save)[i][j++];
    }
  i = 0;
  while ((*save)[i])
    free((*save)[i++]);
  free(*save);
  *save = NULL;
  return (0);
}

int	string_parse(char **buff)
{
  char	**save;
  int	i[3];

  i[0] = 0;
  i[1] = 0;
  i[2] = 0;
  if ((!(*buff)) || (!(*buff)[0]))
    return (0);
  if ((save = my_wordtab(*buff, ' ')) == NULL)
    return (-1);
  while (save[i[0]])
    {
      while (save[i[0]][i[1]])
	{
	  i[2]++;
	  i[1]++;
	}
      i[2]++;
      i[0]++;
      i[1] = 0;
    }
  i[2]--;
  if ((epur_str(buff, i[2], 0, &save)) == -1)
    return (-1);
  return (0);
}

int	my_mem_to_zero(char **buff)
{
  free(*buff);
  if ((*buff = my_xmalloc(1)) == NULL)
    return (-1);
  (*buff)[0] = 0;
  return (0);
}

int	count(char **buff, int i, char **str)
{
  while ((*buff)[i])
    i++;
  if ((*str = my_xmalloc((i + 1) * sizeof(char))) == NULL)
    return (-1);
  (*str)[i] = 0;
  return (0);
}

int	no_space(char **buff)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  while ((*buff)[i] == ' ')
    if (!(*buff)[i++])
      if (my_mem_to_zero(buff) == -1)
	return (0);
  if (count(buff, i, &str) == -1)
    return (-1);
  while ((*buff)[i])
    str[j++] = (*buff)[i++];
  free(*buff);
  if ((*buff = my_xmalloc((j + 1) * sizeof(char))) == NULL)
    return (-1);
  (*buff)[j] = 0;
  i = 0;
  while (--j >= 0)
    (*buff)[j] = str[j];
  free(str);
  if ((string_parse(buff)) == -1)
    return (-1);
  return (0);
}
