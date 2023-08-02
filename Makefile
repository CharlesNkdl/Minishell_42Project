# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 14:49:03 by cnikdel           #+#    #+#              #
#    Updated: 2023/07/06 19:16:59 by cnikdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./cnikdel/new.c ./cnikdel/toknew.c ./cnikdel/tokutilsnew.c ./cnikdel/newutils.c \
       ./cnikdel/freenew.c ./cnikdel/envnew.c ./cnikdel/newtranslator.c \
	   ./cnikdel/newexec.c ./cnikdel/enfantsnew.c ./cnikdel/directoriesnew.c ./cnikdel/cmdhandling.c \
	   ./cnikdel/access.c ./cnikdel/heredoc.c ./cnikdel/execredir.c

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
