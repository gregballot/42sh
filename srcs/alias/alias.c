/*
** alias.c for  in /home/ballot_g/rendu/alias
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 18 11:40:03 2014 Gregoire Ballot
** Last update Sun May 25 20:20:41 2014 TAWFIK
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "alias.h"
#include "basic_funct.h"
#include "structs.h"

static const char	*g_tokens[] =
  {"|", "||", "<", ">", "&", "&&", ";",
   "*", ">>", "<<", "2>>", "2>", "2>&1",
  NULL};

static void		put_syntax_error(const char *msg, const char *token)
{
  write(2, msg, strlen(msg));
  write(2, token, strlen(token));
  write(2, "\n", 1);
}

static int		valid_token(char **entry)
{
  int			i;
  int			j;

  j = 0;
  while (entry[j])
    {
      i = 0;
      while (g_tokens[i])
	{
	  if (my_strcmp(g_tokens[i], entry[j]) == 0)
	    {
	      put_syntax_error(TOKEN_ERROR, entry[j]);
	      return (-1);
	    }
	  ++i;
	}
      ++j;
    }
  return (0);
}

int			check_if_exist(char *varname, t_alias *list)
{
  while (list != NULL)
    {
      if (my_strcmp(list->alias, varname) == 0)
	return (1);
      list = list->next;
    }
  return (0);
}

static int		replace(t_alias **list, char **entry)
{
  t_alias		*tmp;

  tmp = *list;
  while ((*list) != NULL && (my_strcmp((*list)->alias, entry[1]) != 0))
    (*list) = (*list)->next;
  if (*list != NULL)
    {
      free((*list)->cmd);
      if (((*list)->cmd = my_strdup(entry[2])) == NULL)
	return (-1);
    }
  (*list) = tmp;
  free_tab(entry);
  return (0);
}

int			my_alias(t_tab *tab, t_btree **tree)
{
  int			len;

  len = my_wordtab_len((*tree)->right->stock);
  if (len <= 1)
    my_showlist(tab->alias);
  else if (len == 3)
    {
      if (valid_token((*tree)->right->stock) == 0)
	{
	  if (check_if_exist((*tree)->right->stock[1], tab->alias) == 1)
	    {
	      if (replace(&(tab->alias),
			  my_tabdup((*tree)->right->stock)) == -1)
		return (-1);
	    }
	  else
	    push_list(&(tab->alias), my_tabdup((*tree)->right->stock));
	}
    }
  else
    return (my_putstr_error(ALIAS_USAGE));
  return (0);
}
