##
## EPITECH PROJECT, 2018
## minishell
## File description:
## Makefile
##

NAME	=	mysh

LIB	=	-L./lib/printf -lmy

MAKE	=	make -C

SRC	=	src/main.c			\
		src/get_next_line.c		\
		src/loop.c			\
		src/clear_str.c			\
		src/find_path.c			\
		src/parse_path.c		\
		src/builtins.c			\
		src/prompt.c			\
		src/get_envar.c			\
		src/my_exec.c			\
		src/my_str_isalphanum.c		\
		src/my/my_calloc.c		\
		src/my/my_strcat.c		\
		src/my/my_strcmp.c		\
		src/my/my_strlen.c		\
		src/my/my_strdup.c		\
		src/my/my_strcpy.c		\
		src/my/my_str_to_wordtab.c	\
		src/list/print_list.c		\
		src/list/list_len.c		\
		src/list/llist_to_array.c	\
		src/list/remove_node.c		\
		src/list/tab_to_llist.c		\

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -W -Wextra -I include/

all:	$(NAME)

 $(NAME):	$(OBJ)
	$(MAKE) lib/printf
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	$(MAKE) lib/printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) lib/printf clean
	rm $(NAME)

re: clean all

.PHONY: all re clean fclean
