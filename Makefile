# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:08:01 by estrong           #+#    #+#              #
#    Updated: 2021/12/13 16:07:24 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

OBJ		=	pipex.c	utils.c

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

HEADER	=	pipex.h

LIB_DIR		=	libft

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

all :	$(NAME)

$(NAME) :	$(OBJ) $(HEADER)
				@make -C $(LIB_DIR)
				@$(CC) $(FLAGS) $(HEADER) $(LIB_DIR)/libft.a $(OBJ) -o $(NAME)

%.o :		%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@ 

clean :		@make clean -C $(LIB_DIR)
				rm -rf $(SRCS)

fclean :	@make fclean -C $(LIB_DIR)
				rm -rf $(NAME)

re :		fclean all

.PHONY :	all clean fclean re