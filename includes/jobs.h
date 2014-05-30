/*
** jobs.h for 42 in /home/tawfik_e/Mount/tawfik_e/42sh
**
** Made by tawfik
** Login   <tawfik_e@epitech.net>
**
** Started on  Tue May  6 13:59:12 2014 tawfik
** Last update Sun May 25 16:52:34 2014 TAWFIK
*/

#ifndef JOBS_H_
# define JOBS_H_

# include "structs.h"

int	fg_flag(t_tab *, t_btree **);
int	bg_flag(t_tab *, t_btree **);
int	jobs_flag(t_tab *, t_btree **);
void	catch_sig(int);
int	cont_proc(t_proc *);
int	cont_back_proc(t_proc *);

#endif /* !JOBS_H_ */
