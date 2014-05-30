/*
** wordtab.c for  in /home/ballot_g/rendu/alias
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 18 12:02:59 2014 Gregoire Ballot
** Last update Fri May 23 10:34:01 2014 Gregoire Ballot
*/

#include <stdlib.h>
#include "basic_funct.h"
#include "alias.h"

char		**my_duptab(char **tab)
{
  char		**new;
  int		i;

  i = 0;
  if ((new = malloc((my_wordtab_len(tab) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (tab[i])
    {
      if ((new[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      ++i;
    }
  new[i] = NULL;
  return (new);
}

char		**reset_alias(char **cpy, char **alias)
{
  int		i;
  int		j;
  char		**ret;

  i = -1;
  j = 0;
  if ((ret = malloc(sizeof(char *)
		    * (my_wordtab_len(cpy) + my_wordtab_len(alias)))) == NULL)
    return (NULL);
  while (alias[++i] != NULL)
    ret[i] = my_strdup(alias[i]);
  while (cpy[++j] != NULL)
    ret[i++] = my_strdup(cpy[j]);
  ret[i] = NULL;
  free_tab(alias);
  free_tab(cpy);
  cpy = my_duptab(ret);
  free_tab(ret);
  return (cpy);
}
