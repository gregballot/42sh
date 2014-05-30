/*
** letter.c for letter in /home/abollo_h/rendu/PSU_2013_my_select/test/termios
** 
** Made by 
** Login   <abollo_h@epitech.net>
** 
** Started on  Tue Dec 31 13:13:55 2013 
** Last update Sun May 25 13:12:12 2014 
*/

#include <stdlib.h>
#include "basic_funct.h"
#include "structs.h"
#include "termcaps.h"

char	*del_letter(char *stock, unsigned long int c, t_comp *count)
{
  char	*ptr;
  int	i;
  int	j;

  i = 0;
  j = 0;
  (void)c;
  if ((ptr = my_xmalloc((count->save + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (i < count->save)
    {
      if ((j == count->compt) && (count->compt != count->save))
	j++;
      else if (stock)
	ptr[i++] = stock[j++];
    }
  ptr[i] = 0;
  if (ptr[0] == 0)
    {
      free(ptr);
      ptr = NULL;
    }
  free(stock);
  return (ptr);
}

char	*add_letter(char *stock, unsigned long int c, t_comp *count)
{
  char	*ptr;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((ptr = my_xmalloc((count->save + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (i < count->save)
    {
      if ((i == count->compt) && (count->compt != count->save))
	ptr[i++] = c;
      else if (stock)
	ptr[i++] = stock[j++];
      else
	return (NULL);
    }
  if (count->save == count->compt)
    ptr[i++] = c;
  else if (stock)
    ptr[i++] = stock[j];
  ptr[i] = 0;
  free(stock);
  return (ptr);
}
