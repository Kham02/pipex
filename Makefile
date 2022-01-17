# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 19:06:57 by estrong           #+#    #+#              #
#    Updated: 2022/01/12 13:47:38 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

OBJ		=	pipex.c	utils.c	\

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

HEADER	=	pipex.h

LFT		=	libft

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re

all :	$(NAME)

$(NAME) :
	$(MAKE) -C ./libft
	$(CC) -c ${FLAGS} ${OBJ} -I libft/
	$(CC) ${SRCS} -o ${NAME} libft/libft.a

clean :
	rm -f $(SRCS)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft
re : fclean all