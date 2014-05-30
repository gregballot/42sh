/*
** globbing.c for globbing in /home/le-bor_d/rendu/42sh/srcs/globbing
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Wed Apr 30 11:29:01 2014 le-bor_d
** Last update Sat May 24 18:32:49 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <errno.h>
#include "structs.h"
#include "basic_funct.h"
#include "globbing.h"

static int	contain_star(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '*' || str[i] == '?' || str[i] == '[')
      return (1);
  return (0);
}

static char	**my_tabcat(char **stock, char **args)
{
  char		**ret;
  int		i;
  int		j;
  int		size;

  i = -1;
  j = -1;
  size = my_wordtab_len(stock) + my_wordtab_len(args);
  if (!(ret = malloc((size + 2) * sizeof(char *))))
    return (NULL);
  i = -1;
  while (stock != NULL && stock[++i] != NULL)
    {
      if (contain_star(stock[i]) == 0)
	ret[++j] = my_strdup(stock[i]);
      free(stock[i]);
    }
  free(stock);
  i = -1;
   while (args != NULL && args[++i] != NULL)
     ret[++j] = my_strdup(args[i]);
  ret[++j] = NULL;
  return (ret);
}

static int	fill_glob(t_list *tmp, glob_t *glob_struct)
{
  int		first;
  int		i;

  i = -1;
  first = 0;
  while (tmp->stock[++i] != NULL)
    {
      if (first == 0 && contain_star(tmp->stock[i]) == 1)
	{
	  first = 1;
	  if (glob(tmp->stock[i], GLOB_MARK
		   | GLOB_BRACE, NULL, glob_struct) != 0)
	    return (-1);
	}
      else if (contain_star(tmp->stock[i]) == 1)
	if (glob(tmp->stock[i], GLOB_APPEND | GLOB_BRACE
		 | GLOB_MARK, NULL, glob_struct) != 0)
	  return (-1);
    }
  return (0);
}

void		exec_globbing(t_list *list, t_tab *tab)
{
  glob_t	glob_struct;
  t_list	*tmp;

  (void)tab;
  tmp = list;
  if (isatty(0) == 0)
    return ;
  while (tmp->stock != NULL)
    {
      glob_struct.gl_pathv = NULL;
      glob_struct.gl_offs = 0;
      if (fill_glob(tmp, &glob_struct) != -1)
  	{
  	  if (glob_struct.gl_pathv != NULL)
  	    tmp->stock = my_tabcat(tmp->stock,
  				   my_tabdup(glob_struct.gl_pathv));
  	  globfree(&glob_struct);
  	}
      tmp = tmp->next;
    }
}
