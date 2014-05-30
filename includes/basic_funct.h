/*
** basic_funct.h for basic in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Fri Apr 25 11:15:35 2014 le-bor_d
** Last update Sun May 25 16:49:56 2014 le-bor_d
*/

#ifndef BASIC_FUNCT_H_
# define BASIC_FUNCT_H_

# include <sys/types.h>
# include "structs.h"

/*
**	add_equal.c
*/
char	*add_equal(char **);

/*
**	free_all.c
*/
void	free_data(t_list *);
void	free_all(t_btree **, t_list **);
void    free_stock(char **);

/*
**	get_next_line.c
*/
char	*get_next_line(const int);

/*
**	init_var.c
*/
void	init_var(t_get **, int);

/*
**	my_getenv.c
*/
char	*my_getenv(char **, const char *);

/*
**	my_getnbr_basemod.c
*/
int	my_getnbr_base(const char *, const char *, int);
int	my_putnbr(int);
int	my_putnbr(int);

/*
**	my_putchar.c
*/
int	my_putchar(int);

/*
**	my_putstr.c
*/
int	my_putstr(const char *);
int	my_putstr_error(const char *);

/*
**	my_strcat.c
*/
char	*my_strcat(const char *, char *);
char	*my_strncat(const char*, char*, int);

/*
**	my_strcmp.c
*/
int	my_strcmp(const char *, const char *);

/*
**	my_strdup.c
*/
char	*my_strdup(const char *);

/*
**	my_strlen.c
*/
int	my_strlen(const char *);

/*
**	my_strncmp.c
*/
int	my_strncmp(const char *, const char *, const int);

/*
**	my_strslashcat.c
*/
char	*my_strslashcat(const char *, const char *);

/*
**	my_strtildecat.c
*/
char	*my_strtildecat(char *, char *);

/*
**	my_tabdup.c
*/
char	**my_tabdup(char **);

/*
**	my_wordtab.c
*/
char	**my_wordtab(char *, char);
int	my_wordtab_len(char **);

/*
**	my_xmalloc.c
*/
void	*my_xmalloc(long);

/*
**	proc.c
*/
t_proc	*my_put_in_list(t_proc *, pid_t, pid_t, char *);
t_proc	*my_delete_from_list(t_proc *);
t_proc	*my_delete_from_list2(t_proc *);

#endif /* !BASIC_FUNCT_H_ */
