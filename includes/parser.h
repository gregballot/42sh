/*
** parser.h for parseur in /home/le-bor_d/rendu/42sh/includes
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Fri Apr 25 10:44:32 2014 le-bor_d
** Last update Sun May 25 16:49:12 2014 le-bor_d
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "structs.h"

# define FD_0 0
# define FD_1 1
# define FD_2 2
# define CLOSE 0
# define DUP 1
# define SET 2

# define SEP 0
# define RED_L 1
# define RED_R 2
# define PIPE 3
# define AND_OR 4
# define PAR 5
# define JOBS 6

/*
**	add_elem.c
*/
int		count_sent(t_list **);
int		add_op_bis(t_list **, t_list **);
int		add_op(t_list **, t_list **);
int		other_stock(t_list **, t_list **);
int		new_stock(t_list **, t_list **);

/*
**	lexer.c
*/
int		lex_red_r(t_list **);
int		lex_sent(t_list **);
t_list		*add_to_new_stock(t_list **);
t_list	        *lexer(t_list **);

/*
**	parenthesis.c
*/
int		count_par(t_list **);

/*
**	lexer_fonc.c
*/
int		lex_pipe(t_list **);
int		lex_red_l(t_list **);
int		lex_orand(t_list **);
int		lex_par(t_list **);
int		lex_scolon(t_list **);

/*
**	load_leaf.c
*/
t_btree		*first_value(int, int);
void		until_close_par(t_list **);
void		new_leaf(t_list **, t_btree **, int);
t_btree		*load_tree(t_list **, int *);
t_btree		*exception(t_list **);

/*
**	op_and_sep.c
*/
int	        find_sep(char *, int);
int		find_op(char *, int);

/*
**	parenthesis.c
*/
int		count_par(t_list **);

/*
**	parser.c
*/
void		init_to_zero(t_tab *);
int		init_tree(t_btree **);
t_btree		*separtor_found(t_btree *, t_list **, int, t_btree **);
t_btree		*add_on_tree(t_btree *, t_list **, int, int);
int		parser(t_list **, t_tab *);

/*
**	searching.c
*/
int		search(char *, int, int);

#endif /* !PARSER_H_ */
