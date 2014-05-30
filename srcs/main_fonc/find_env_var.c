/*
** find_env_var.c for find_env_var in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Fri Apr 25 15:15:26 2014 le-bor_d
** Last update Sun May 25 19:18:22 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <basic_funct.h>
#include <structs.h>
#include "backquote.h"
#include "main_funct.h"

static int	simple_quote(char *str, int *i)
{
  if (str[*i] == '\'')
    {
      ++(*i);
      while (str[*i] && str[*i] != '\'')
	++(*i);
    }
  if (str[*i] == '\0')
    --(*i);
  return (0);
}

char		*my_get_special_env(char **env, char *var)
{
  int		i;
  int		j;
  char		*ret;

  i = -1;
  if (var == NULL)
    return (NULL);
  while (env != NULL && env[++i] != NULL)
    {
      j = -1;
      while (var[++j] != '\0' && env[i][j] == var[j] && env[i][j] != '=')
	;
      if (env[i][j] == '=' && var[j] == '\0')
	{
	  ret = my_strdup(&(env[i][j]));
	  free(var);
	  return (ret);
	}
    }
  free(var);
  return (NULL);
}

static char	*my_ret_var(char *str, t_tab *tab)
{
  char		*var_env;

  if ((var_env = malloc(11)) == NULL)
    return (NULL);
  var_env[10] = 0;
  str[0] = 0;
  if (sprintf(var_env, "%d", tab->last_status) < 0)
    (void)write(2, "Sprintf failed\n", 15);
  return (var_env);
}

static char	*my_get_var_env(char *str, t_tab *tab, int *move)
{
  int		i;
  int		j;
  char		*var_env;
  char		*ret;

  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = -1;
  if (str[1] == '{')
    *move += ++i;
  while (str[i] != 0 && str[++i] != '\0' && str[i] != ' ' && str[i] != '"'
	 && str[i] != '@' && str[i] != '}')
    ret[++j] = str[i];
  ret[++j] = 0;
  *move = *move + i;
  if (str[1] == '?' && (str[2] == ' ' || str[2] == '}'
			|| str[2] == '"' || str[2] == 0))
    return (my_ret_var(str, tab));
  str[0] = 0;
  if ((var_env = my_get_special_env(tab->env, ret)) == NULL)
    return (my_strdup(" "));
  return (my_strdup(var_env + 1));
}

char		*find_env_var(char *str, t_tab *tab, int move)
{
  char		*ret;
  char		*env_var;
  int		i;

  i = -1;
  ret = str;
  while (str && str[++i] != '\0')
    if ((!simple_quote(str, &i) && (str[i] == '$')))
      {
	move = i;
	env_var = my_get_var_env(&(str[i]), tab, &move);
	if (env_var != NULL)
	  {
	    if (str[0] == 0)
	      ret = env_var;
	    else if ((ret = my_strfreecat(my_strdup(str), env_var, 2)) == NULL)
	      return (NULL);
	    if (move > 0 && str[move - 1] != 0 && str[move] != 0)
	      if ((ret = my_strfreecat(ret, my_strdup(&str[move]), 2)) == NULL)
	    	return (NULL);
	    free(str);
	    str = ret;
	  }
      }
  return (ret);
}
