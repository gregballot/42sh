##
## Makefile for Makefile in /home/abollo_h/rendu/42sh
## 
## Made by 
## Login   <abollo_h@epitech.net>
## 
## Started on  Sun May 25 16:39:16 2014 
## Last update Sun May 25 16:40:50 2014 
##

SRC 	=	./srcs/main_fonc/main.c				\
		./srcs/main_fonc/check_error.c			\
		./srcs/main_fonc/parse_line.c			\
		./srcs/main_fonc/elem.c				\
		./srcs/main_fonc/find_env_var.c			\
		./srcs/main_fonc/signal.c			\
		./srcs/main_fonc/parsing.c			\
		./srcs/main_fonc/exec_all.c			\
		./srcs/main_fonc/load_file.c			\
		./srcs/main_fonc/add_elem.c			\
		./srcs/main_fonc/tilde_funct.c			\
		./srcs/main_fonc/clean_backslash.c

TERMCAPS =	./srcs/termcaps/other_char_b.c			\
		./srcs/termcaps/termcaps.c			\
		./srcs/termcaps/other_char_a.c			\
		./srcs/termcaps/move.c				\
		./srcs/termcaps/character.c			\
		./srcs/termcaps/miniterm.c			\
		./srcs/termcaps/history.c			\
		./srcs/termcaps/my_autcomplete.c		\
		./srcs/termcaps/my_autcomplete2.c		\
		./srcs/termcaps/my_autocomplete3.c		\
		./srcs/termcaps/autocomp_glob.c

BUILTIN	=	./srcs/builtin/cd_option.c			\
		./srcs/builtin/echo.c				\
		./srcs/builtin/echo2.c				\
		./srcs/builtin/env.c				\
		./srcs/builtin/setenv.c				\
		./srcs/builtin/unsetenv.c			\
		./srcs/builtin/flag.c				\
		./srcs/builtin/fg.c				\
		./srcs/builtin/jobs.c

PL	=	./srcs/parser_lexer/searching.c			\
		./srcs/parser_lexer/lexer.c			\
		./srcs/parser_lexer/add_elem.c			\
		./srcs/parser_lexer/lexer_fonc.c		\
		./srcs/parser_lexer/parser.c			\
		./srcs/parser_lexer/parenthesis.c		\
		./srcs/parser_lexer/op_and_sep.c		\
		./srcs/parser_lexer/load_leaf.c			\
		./srcs/parser_lexer/verif_val.c

PIPE_RED =	./srcs/pipe_and_red/redirection.c		\
		./srcs/pipe_and_red/pipe.c			\
		./srcs/pipe_and_red/all_left_c.c		\
		./srcs/pipe_and_red/all_right_c.c		\
		./srcs/pipe_and_red/add_arg.c			\
		./srcs/pipe_and_red/free_tree.c			\
		./srcs/pipe_and_red/exec_command.c		\
		./srcs/pipe_and_red/built_or_exec.c		\

FONC	=	./srcs/basic_fonc/add_equal.c			\
		./srcs/basic_fonc/my_xmalloc.c			\
		./srcs/basic_fonc/my_wordtab.c			\
		./srcs/basic_fonc/my_getenv.c			\
		./srcs/basic_fonc/get_next_line.c		\
		./srcs/basic_fonc/my_strcmp.c			\
		./srcs/basic_fonc/my_strncmp.c			\
		./srcs/basic_fonc/my_putstr.c			\
		./srcs/basic_fonc/my_strlen.c			\
		./srcs/basic_fonc/my_putchar.c			\
		./srcs/basic_fonc/my_strtildecat.c		\
		./srcs/basic_fonc/my_strdup.c			\
		./srcs/basic_fonc/my_strcat.c			\
		./srcs/basic_fonc/init_var.c			\
		./srcs/basic_fonc/my_tabdup.c			\
		./srcs/basic_fonc/free_all.c			\
		./srcs/basic_fonc/my_getnbr_basemod.c		\
		./srcs/basic_fonc/my_strslashcat.c		\
		./srcs/basic_fonc/proc.c			\
		./srcs/basic_fonc/my_getnbr.c			\

ALIAS	=	./srcs/alias/alias.c				\
		./srcs/alias/find_alias.c			\
		./srcs/alias/list.c				\
		./srcs/alias/wordtab.c				\
		./srcs/alias/unalias.c

PROMPT	=	./srcs/prompt/prompt.c				\
		./srcs/prompt/date_funct.c			\
		./srcs/prompt/date_funct2.c			\
		./srcs/prompt/uid_funct.c			\
		./srcs/prompt/name_funct.c			\
		./srcs/prompt/files_funct.c			\
		./srcs/prompt/characters_funct.c		\
		./srcs/prompt/git_flag.c

GLOB	=	./srcs/globbing/globbing.c

JOBS	=	./srcs/jobs/background.c

BQUOTE	=	./srcs/backquote/backquote.c

WAIT	=	./srcs/wait/wait.c

NAME	=	dogesh

OBJ	=	$(SRC:.c=.o) $(TERMCAPS:.c=.o) $(BUILTIN:.c=.o)	\
		$(PL:.c=.o) $(PIPE_RED:.c=.o) $(FONC:.c=.o)	\
		$(ALIAS:.c=.o) $(GLOB:.c=.o) $(PROMPT:.c=.o)	\
		$(JOBS:.c=.o) $(BQUOTE:.c=.o) $(WAIT:.c=.o)

CC	=	cc

CFLAGS +=	-I./includes/ -W -Wall -Wextra

CP	=	cp

RM	=	rm -f

all: 		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
