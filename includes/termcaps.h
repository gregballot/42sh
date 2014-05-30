/*
** termcaps.h for  in /home/locate_a/rendu/42sh/final/42sh
** 
** Made by a
** Login   <locate_a@epitech.net>
** 
** Started on  Fri May  9 18:51:44 2014 a
** Last update Sun May 25 16:48:34 2014 le-bor_d
*/

#ifndef TERMCAPS_H_
# define TERMCAPS_H_

# include <glob.h>
# include "structs.h"

# define DISCLAIMER "Display all %d possibilites ? (yes or no)\n"

/*
**	character.c
*/
char	*del_letter(char *, unsigned long int, t_comp *);
char	*add_letter(char *, unsigned long int, t_comp *);

/*
**	miniterm.c
*/
int	char_cl(char **, unsigned long int, t_comp *, t_tab *);
int	char_nl(char **, unsigned long int, t_comp *, t_tab *);
int	char_del(char **, unsigned long int, t_comp *, t_tab *);
int	char_letter(char **, unsigned long int, t_comp *, t_tab *);
int     char_move(char **, unsigned long int, t_comp *, t_tab *);

/*
**	move.c
*/
int	term_left(char **, unsigned long int, t_comp *, t_tab *);
int	term_right(char **, unsigned long int, t_comp *, t_tab *);
int	term_up(char **, unsigned long int, t_comp *, t_tab *);
int	term_down(char **, unsigned long int, t_comp *, t_tab *);

/*
**	other_char_b.c
*/
int	paste(char **, unsigned long int, t_comp *, t_tab *);
int	char_ctr_k(char **, unsigned long int, t_comp *, t_tab *);
int	ctrl_term_right(char **, unsigned long int, t_comp *, t_tab *);
int	ctrl_term_left(char **, unsigned long int, t_comp *, t_tab *);

/*
**	other_char_a.c
*/
int	char_neg(char **, unsigned long int, t_comp *, t_tab *);
int	char_ctr_a(char **, unsigned long int, t_comp *, t_tab *);
int	char_ctr_c(char **, unsigned long int, t_comp *, t_tab *);
int	char_ctr_e(char **, unsigned long int, t_comp *, t_tab *);
int	char_ctr_g(char **, unsigned long int, t_comp *, t_tab *);

/*
**	termcaps.c
*/
int	loop(char **, unsigned long int *, t_tab *, t_comp *);
int	character(char **, unsigned long int, t_tab *);
int	termcaps(char **, t_tab *);
int	init_list(t_list **, char *, int *);
int	my_getentry(t_tab *);
char	*my_getline(t_tab *, int *);

/*
**	autocompletion
*/
int	disclaimer(glob_t*, t_tab*, char**);
int	my_tablen(char**);
int	clear_c(char*, char);
int	one_match(char**, char*, glob_t*, t_comp*);
int	auto_complete(char**, unsigned long int, t_comp*, t_tab*);
int	my_glob_return(glob_t*, char *, int);
int	arg_complete(char**, t_tab*, t_comp*, glob_t*);
void	aff_glob(glob_t*);
int	bin_completion(char**, t_tab*, glob_t*, t_comp*);
int	every_glob(t_tab*, glob_t*);
int	epur_duplicates(char **);
int	glob_here(glob_t*, char**, t_tab*);
int	check_common_char(char**, char**, char*, t_comp*);

/*
**	history.c
*/
int	next_list(t_list **, char *, t_list *);
int	init_list(t_list **, char *, int *);

#endif /* !TERMCAPS_H_ */
