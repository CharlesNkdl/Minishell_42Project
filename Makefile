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

SRCS = 		./src/begin.c \
			./src/access.c \
			./src/begininit.c \
			./src/child.c \
			./src/cmdhandling.c \
			./src/dircheck.c \
			./src/env.c \
			./src/exec.c \
			./src/execredir.c \
			./src/freefct.c \
			./src/freefctwo.c \
			./src/heredoc.c \
			./src/signals.c \
			./src/token.c \
			./src/tokentwo.c \
			./src/tokenutils.c \
			./src/translator.c \
			./src/builtins.c \
			./src/cd.c \
			./src/echo.c \
			./src/envbuilt.c \
			./src/exit.c \
			./src/export.c \
			./src/pwd.c \
			./src/unset.c \
			./src/utils.c \
			./src/pipbuilt.c \
			./src/builtutils.c \
			./src/execsolobuilt.c \
			./src/childtwo.c \
			./src/exportwo.c \


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
	$(CC) $(AFLAGS) $(SRCS) $(LIBFT)  $(LIBFT) $(LIB) $(INC) -o $(NAME)

fclean : clean
	$(MAKE) fclean -C ./Libft
	$(RM) $(NAME)

clean :
	$(MAKE) clean -C ./Libft
	$(RM) *.o

re : fclean all

.PHONY : all fclean clean re
