# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 14:49:03 by cnikdel           #+#    #+#              #
#    Updated: 2023/06/16 17:36:47 by cnikdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./cnikdel/main.c

OBJS = $(SRCS:.c=.o)

CC = cc

AFLAGS =  -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

INC			=	-I ./inc/\
				-I ./Libft/\

LIB = -lreadline -lncurses

RM = rm -rf

NAME = minishell

all : $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(NAME): $(LIBFT)
	$(CC) $(SRCS) $(LIBFT) $(AFLAGS) $(LIBFT) $(LIB) $(INC) -o $(NAME)

fclean : clean
	$(MAKE) fclean -C ./Libft
	$(RM) $(NAME)

clean :
	$(MAKE) clean -C ./Libft
	$(RM) *.o

re : fclean all

.PHONY : all fclean clean re
