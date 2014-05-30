/*
** alias.h for  in /home/ballot_g/rendu/alias
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 18 11:40:08 2014 Gregoire Ballot
** Last update Sun May 25 16:49:44 2014 le-bor_d
*/

#ifndef ALIAS_H_
# define ALIAS_H_

#include "structs.h"

# define ALIAS_USAGE	"Usage : alias name value\n"
# define TOKEN_ERROR	"Alias : invalid token : "

/*
** List Functions
*/
void	my_showlist(t_alias *);
void	free_tab(char **);
void	my_freelist(t_alias *);
int	push_list(t_alias **, char **);
int	push_hist(t_alias_hist **, char *, t_alias *);
char	*match_alias(char *, t_alias *);
void	my_freehisto(t_alias_hist *);
int	check_if_exist(char *, t_alias *);

/*
** Tab Functions
*/
int	my_wordtab_len(char **);
char	**my_duptab(char **);
char	**reset_alias(char **, char **);

/*
** Alias Functions
*/
int     my_alias(t_tab *, t_btree **);
int	my_unalias(t_tab *, t_btree **);

#endif /* !ALIAS_H_ */
