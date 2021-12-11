# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:08:01 by estrong           #+#    #+#              #
#    Updated: 2021/12/11 02:20:59 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

OBJ		=	pipex.c	

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

LIB		=	libft

HEADER	=	pipex.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

all :	$(NAME)

$(NAME) :	$(OBJ) $(HEADER)
				ar rcs $(NAME) $?

%.o :		%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@ 

clean :
			rm -rf $(SRCS)

fclean :
			rm -rf $(NAME)

re :		fclean all

.PHONY :	all clean fclean re