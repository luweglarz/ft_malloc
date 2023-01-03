# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 13:45:51 by lweglarz          #+#    #+#              #
#    Updated: 2021/07/16 13:17:36 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

FLAGS= -Wall -Wextra -Werror

SRCS= $(shell find ./ -type f -name '*.c')

RM	= rm -f

CC = cc

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) libft.h
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
