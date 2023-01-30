# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 10:09:58 by mbouaza           #+#    #+#              #
#    Updated: 2022/11/16 14:28:03 by mbouaza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC 	=	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_putnbr_unsigned.c ft_putnbr_hex_maj.c ft_putnbr_hex_min.c ft_put_ptr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		  ar -rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
