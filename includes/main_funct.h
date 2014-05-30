/*
** main_funct.h for main_funct in /home/le-bor_d/rendu/42sh/includes
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Fri Apr 25 10:41:22 2014 le-bor_d
** Last update Sun May 25 19:18:52 2014 
*/

#ifndef MAIN_FUNCT_H_
# define MAIN_FUNCT_H_
# include "structs.h"

/*
**	signal.c
*/
void		my_signal(void);

/*
**	parsing.c
*/
int		epur_str(char **, int, int, char ***);
int		string_parse(char **);
int		my_mem_to_zero(char **);
int		count(char **, int, char **);
int		no_space(char **);

/*
**	parse_line.c
*/
char		*parse_line(char *, int , int);
char		*add_space(char *, int, int);
int		free_blank(t_list **);
char		*free_str(char **);
char		*seperate(char *, int, int, t_tab *);

/*
**	main.c
*/
int		my_setpath(t_tab *);
int		only_space(t_tab *);

/*
**	exec_all.c
*/
int		is_backslash(const char *, int);
void		to_start(t_list **, int);
int		is_sentence(const char *, int *, int, char *);
int		exec_all(t_tab *, char *);

/*
**	elem.c
*/
int		add_null(t_list **);
int		free_list(t_list **);
void		add_elem(t_list **, char *);
void		del_elem(t_list **, char *);
int		free_elem(t_list **);

/*
**	check_error.c
*/
int		check_access(t_btree **, char *);
void		my_waitpid(pid_t, int *, int, int);
int		my_tputs(const char *, int, int (*)(int));
int		mismatch_thing(char *, int);
int		my_puterror(char *, int);

/*
**	add_elem.c
*/
char		*my_add_char(char *, char, int);
int		other_sentence(t_list **, int, const char *, int);
int		first_sentence(const char *, int *, t_list **);
int		other_word(const char *, t_list **, int, int *);
int		first_word(const char *, int *, t_list **);

/*
**	find_env_var.c
*/
char		*find_env_var(char *, t_tab *, int);
char		*my_get_special_env(char **, char *);

/*
**	load_file.c
*/
int		load_conf_file(t_tab *, char *);

/*
**	tilde_funct.c
*/
t_list		*replace_tilde(t_list *, t_tab *);

/*
**	clean_backslash.c
*/
char		*clean_backslash(t_list **, t_list **);

/*
**	my_getnbr.c
*/
int		my_getnbr(char *);

#endif /* !MAIN_FUNCT_H_ */
