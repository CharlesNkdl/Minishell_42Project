# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 14:49:03 by cnikdel           #+#    #+#              #
#    Updated: 2023/05/16 23:56:34 by cnikdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./src/fract_ol.c ./src/funct.c ./src/init.c \
		./src/utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

MFLAGS = ./mlx/libmlx.a

AFLAGS =  -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

INC			=	-I ./inc/\
				-I ./Libft/\
				-I ./mlx/

LIB = -L./mlx -lmlx -lXext -lX11 -lm

RM = rm -rf

NAME = fractol

all : $(NAME)

$(MFLAGS):
	$(MAKE) -C ./mlx
	$(MAKE) -C ./Libft

$(NAME): $(MFLAGS)
	$(CC) $(SRCS) $(MFLAGS) $(AFLAGS) $(LIBFT) $(LIB) $(INC) -o fractol

fclean : clean
	$(MAKE) fclean -C ./Libft
	$(RM) $(NAME)

clean :
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./Libft
	$(RM) *.o

re : fclean all

.PHONY : all fclean clean re
