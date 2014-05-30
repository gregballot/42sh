/*
** prompt.h for prompt in /home/le-bor_d/rendu/42sh
**
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
**
** Started on  Sun May  4 12:11:51 2014 le-bor_d
** Last update Sun May 25 16:49:05 2014 le-bor_d
*/

#ifndef PROMPT_H_
# define PROMPT_H_

# include <time.h>
# include "structs.h"

# define VERSION "3.00"
# define VERSION_2 "3.00.2"

/*
**	prompt.c
*/
void	prompt(t_tab *);
void    backslash_no(t_tab *, char *, struct tm *, int);

/*
**	date_funct.c
*/
void	d_flag(t_tab *, char *, struct tm *, int);
void	t_flag(t_tab *, char *, struct tm *, int);
void	capital_t_flag(t_tab *, char *, struct tm *, int);
void	at_flag(t_tab *, char *, struct tm *, int);
void	a_flag(t_tab *, char *, struct tm *, int);

/*
**	date_funct.c
*/
void		t_flag2(struct tm *);
void		capital_t_flag2(struct tm *);
void		at_flag1(struct tm *);
void		at_flag2(struct tm *);

/*
**	uid_funct.c
*/
void	sharp_flag(t_tab *, char *, struct tm *, int);
void	dollar_flag(t_tab *, char *, struct tm *, int);
void    v_flag(t_tab *, char *, struct tm *, int);
void    capital_v_flag(t_tab *, char *, struct tm *, int);
void    h_flag(t_tab *, char *, struct tm *, int);

/*
**	name_funct.c
*/
void    name_flag(t_tab *, char *, struct tm *, int);
void    user_flag(t_tab *, char *, struct tm *, int);

/*
**      files_funct.c
*/
void    w_flag(t_tab *, char *, struct tm *, int);
void    capital_w_flag(t_tab *, char *, struct tm *, int);

/*
**	charcacyers_funct.c
*/
void    backslash_n(t_tab *, char *, struct tm *, int);
void    backslash_a(t_tab *, char *, struct tm *, int);
void    backslash_r(t_tab *, char *, struct tm *, int);
void    backslash_slash(t_tab *, char *, struct tm *, int);
void    backslash_e(t_tab *, char *, struct tm *, int);

/*
**	git_flag.c
*/
void    git_flag(t_tab *, char *, struct tm *, int);

/*
**	signal.c
*/
void	check_all_proc();

#endif /* !PROMPT_H_ */
