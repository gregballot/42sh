/*
** structs.h for structs in /home/abollo_h/rendu/42sh
**
** Made by
** Login   <abollo_h@epitech.net>
**
** Started on  Sat May 24 16:10:43 2014
** Last update Sun May 25 22:36:12 2014 
*/

#ifndef STRUCTS_H_
# define STRUCTS_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>

# define BUFF_SIZE	1024

/*
** Alias data structure
*/
typedef struct		s_proc
{
  pid_t			gpid;
  pid_t			last_pid;
  char			*cmd;
  struct s_proc		*next;
  struct s_proc		*prev;
}			t_proc;

typedef struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_alias_hist
{
  char			*history;
  struct s_alias_hist	*next;
}			t_alias_hist;

typedef struct		s_match
{
  char			*ret;
  t_alias_hist		*history;
}			t_match;

/*
**	Data structures
*/
typedef struct		s_list
{
  char			*data;
  char			**stock;
  int			quote;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef	struct		s_tab
{
  char			*buff;
  char			***stock;
  char			**path;
  char			**env;
  int			pipefd[2][2];
  int			info[3];
  char			**save;
  int			pipe;
  pid_t			pid;
  int			status;
  int			last_status;
  t_alias		*alias;
  t_list		*list;
  int			exit_flag;
  int			exit_value;
  pid_t			sid;
  int			bquote;
  int			spepipe[2];
  char			*stock_pipe;
  int		        count;
  int			move;
}			t_tab;

typedef struct		s_lex
{
  int			op;
  int			(*ptr)(t_list **);
}			t_lex;

typedef struct		s_btree
{
  char			**stock;
  char			info[2];
  int			par;
  struct s_btree	*left;
  struct s_btree	*right;
}			t_btree;

typedef struct		s_error
{
  pid_t			nbr;
  char			*str;
}			t_error;

typedef struct		s_comp
{
  int			i;
  unsigned long int	n;
  int			save;
  int			compt;
  int   		ret;
}			t_comp;

typedef struct		s_get
{
  int			fd;
  char			buff[BUFF_SIZE];
  char			*stock;
  t_comp		count;
  int			msg;
  struct s_get		*next;
}			t_get;

typedef struct		s_pid
{
  int			nbr;
  int			jobs;
  struct s_pid		*next;
}			t_pid;

typedef struct		s_term
{
  unsigned long int	nbr;
  int			(*ptr)(char **, unsigned long int, t_comp *, t_tab *);
}			t_term;

typedef struct		s_op
{
  char			*str;
  int			(*ptr)(t_tab *, t_btree **);
}			t_op;

/*
**	Data prompt
*/
typedef struct		s_prompt
{
  char			*str;
  void			(*ptr)(t_tab *, char *, struct tm *, int);
}			t_prompt;

#endif /* !STRUCTS_H_ */
