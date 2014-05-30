/*
** pipe_and_red.h for pipe_and_red in /home/le-bor_d/rendu/42sh/includes
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Fri Apr 25 13:42:14 2014 le-bor_d
** Last update Sun May 25 16:52:24 2014 TAWFIK
*/

#ifndef PIPE_AND_RED_H_
# define PIPE_AND_RED_H_

# include "structs.h"

# define QUOTE		'\''
# define D_QUOTE	'\"'

# define OP		0
# define NO_OP		-1

# define YES		1
# define NO		0

# define CLEAN		0
# define NOT		1

/*
**	add_arg.c
*/
void	ret_value(char **, int);
void	free_tab(char **);
int	calc_size(char ***, char **);
int	save_arg(char ***, char **, int);

/*
**	all_left_c.c
*/
int	write_on_file(t_tab *, t_btree **);
int	double_left_c(t_tab *, t_btree **);
int	left_c(t_tab *, t_btree **);

/*
**	all_right_c.c
*/
int	err_and_no_right_c(t_tab *, t_btree **);
int	err_double_right_c(t_tab *, t_btree **);
int	double_right_c(t_tab *, t_btree **);
int	err_right_c(t_tab *, t_btree **);
int	right_c(t_tab *, t_btree **);

/*
**	exec_command.c
*/
int	exec_command(t_tab *, t_btree **, t_pid **);

/*
**	fill_file.c
*/
void	fill_file(int, int);

/*
**	free_tree.c
*/
void	relink_tree(t_btree **);

/*
**	pipe.c
*/
int	exist(t_tab *, t_btree **);
void	fd_is_on(t_tab *, int);
int	exec_pipe(t_tab *, t_btree **, int, t_pid **);
void	all_fd(t_tab *, int);

/*
**	redirection.c
*/
t_btree	*execution(t_tab *, t_btree **);
int	my_separator(t_tab *,  t_btree **, int, t_pid **);
int	send_to_arg(t_tab *, t_btree **);
int	other_execute(t_tab *, t_btree **, t_pid **);
int	execute(t_tab *, t_btree **, t_pid **);

#endif /* !PIPE_AND_RED_H_ */
