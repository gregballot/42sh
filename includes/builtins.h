/*
** builtins.h for builtins4 in /home/le-bor_d/rendu/42sh/includes
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Fri Apr 25 12:47:26 2014 le-bor_d
** Last update Sun May 25 16:49:36 2014 le-bor_d
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "structs.h"

/*
**	cd_option.c
*/
int	change_dir(char *, char *, t_tab *);
int	cd_tilde(t_btree **, t_tab *, char *);
int	cd_minus(t_btree **, t_tab *, char *);

/*
**	echo.c
*/
# define READ	0
# define WRITE	1

char	*echo_get_options(int *, char **);
void	my_putchar_echo2(char *, int *);
void	my_putchar_echo(char *, int *);
int	my_put_echo(char *, char);
int	echo_flag(t_tab *, t_btree **);

/*
**	echo2.c
*/
int	echo_unique(char *);
int	incorrect_param(char *);
void	echo_help(void);

/*
**	env.c
*/
int	env_flag(t_tab *, t_btree **);
int	put_env(char **, t_tab *);

/*
**	flag.c
*/
int	exit_flag(t_tab *, t_btree **, int);
int	cd_flag(t_tab *, t_btree **);

/*
**	setenv.c
*/
int	my_setenv(t_tab *, t_btree **);
int	is_exist(t_tab *, t_btree **);
int	setenv_flag(t_tab *, t_btree **);

/*
**	unsetenv.c
*/
int	verify_path(t_tab *, t_btree **, char **);
int	init_save(char ***, t_tab *);
int	my_unsetenv(t_tab *, t_btree **);
int	unsetenv_flag(t_tab *, t_btree **);

#endif /* !BUILTINS_H_ */
