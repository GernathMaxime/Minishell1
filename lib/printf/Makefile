##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## For prinft
##

NAME	=	libmy.a

CC	=	gcc

ARCH	=	ar rc

SRCS	=	src/my_put_nbr.c			\
		src/my_revstr.c			\
		src/my_strlen.c			\
		src/my_binary.c			\
		src/my_octal.c				\
		src/my_hexa.c				\
		src/my_putnbr_base.c			\
		src/my_putchar.c			\
		src/my_putstr.c			\
		src/va/va_putfct.c			\
		src/va/va_base.c			\
		src/my_adress.c			\
		src/show_unprintable.c			\
		src/format.c				\
		my_printf.c				\

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Werror -I include/

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCH) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
