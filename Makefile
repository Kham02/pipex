# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 19:06:57 by estrong           #+#    #+#              #
#    Updated: 2022/01/07 19:28:50 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

OBJ		=	pipex.c		utils.c

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

HEADER	=	pipex.h

LFT		=	libft/libft.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re

all :	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@make re -C ./libft
	$(CC) $(OBJ) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS)  -c $< -o $@

clean :		#@make clean -C $(LFT)
				rm -rf $(SRCS)

fclean :	#@make fclean -C $(LFT)
				rm -rf $(NAME)

re :		fclean all