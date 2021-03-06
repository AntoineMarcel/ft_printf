# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 07:59:40 by amarcel           #+#    #+#              #
#    Updated: 2019/09/10 17:03:05 by abelkhay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC= gcc
CFLAGS = -Wall -Werror -Wextra

SRC =	./src/ft_printf.c\
		./src/parse.c\
		./src/convert.c\
		./src/readconv.c\
		./src/readconv2.c\
		./src/print.c\
		./src/utils.c\

OBJ= ./ft_printf.o\
	./parse.o\
	./convert.o\
	./readconv.o\
	./readconv2.o\
	./print.o\
	./utils.o\

OBJS = ./libft/*.o
LIBFT= ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		make -C ./libft/
		cp libft/libft.a ./$(NAME)
		gcc -c $(SRC) $(CFLAGS)
		ar rc $(NAME) $(OBJ) $(OBJS)
		ranlib $(NAME)

clean:
		/bin/rm -rf $(OBJ)
		make -C libft fclean

fclean: clean
		/bin/rm -rf $(NAME)
		/bin/rm -rf ./libft/libft.a

re: fclean all

.PHONY: all, clean, fclean, re


