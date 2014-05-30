/*
** unalias.c for unalias in /home/le-bor_d/rendu/42sh/srcs/alias
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Sun Apr 27 10:42:51 2014 le-bor_d
** Last update Sat May 24 15:11:13 2014 TAWFIK
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "alias.h"
#include "basic_funct.h"
#include "structs.h"

static t_alias	*delete_from_list(t_alias *alias, char *varname)
{
  t_alias	*delete;
  t_alias	*tmp;

  tmp = alias;
  if (my_strcmp(alias->alias, varname) == 0)
    {
      delete = alias;
      alias = alias->next;
      free(delete->alias);
      free(delete->cmd);
      return (alias);
    }
  while (alias->next != NULL && my_strcmp(alias->next->alias, varname) != 0)
    alias = alias->next;
  delete = alias->next;
  alias->next = delete->next;
  free(delete->alias);
  free(delete->cmd);
  free(delete);
  return (tmp);
}

int		my_unalias(t_tab *tab, t_btree **tree)
{
  int		len;
  int		i;

  i = 0;
  len = my_wordtab_len((*tree)->right->stock);
  if (len <= 1)
    write(2, "Please specify an alias\nUSAGE: unalias [alias] ...\n", 52);
  else
    {
      while ((*tree)->right->stock[++i] != NULL)
	{
	  if (check_if_exist((*tree)->right->stock[i], tab->alias) == 0)
	    fprintf(stderr, "unalias: Unknown alias: %s\n",
		    (*tree)->right->stock[i]);
	  else
	    tab->alias = delete_from_list(tab->alias,
					  (*tree)->right->stock[i]);
	}
    }
  return (0);
}
