# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2021/11/18 11:40:32 by amarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c			\
		ft_print_format.c	\
		ft_itoa_hex.c		

OBJS = $(SRCS:.c=.o)
HDRS = libftprintf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@ 

all:	$(NAME)

$(NAME): $(OBJS)
		${MAKE} -C ./libft
		cp ./libft/libft.a ${NAME}
		ar rcs $(NAME) $(OBJS)
		
clean:
		rm -rf $(OBJS)
		$(MAKE) -C ./libft clean

fclean:	clean
		rm -rf $(NAME)
		$(MAKE) -C ./libft fclean

re:		fclean all

.PHONY:	all clean fclean re 


