#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 16:14:18 by cnikdel           #+#    #+#              #
#    Updated: 2023/04/24 14:37:13 by cnikdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -I

NAME		= libft.a

INCLUDE 	= Headers/

SRC_DIR		=	Functions/

OBJ_DIR		=	obj/

AR			=	ar rcs

GNL_DIR		=	gnl/
GNL			=	get_next_line_bonus get_next_line_utils_bonus

IS_DIR		=	is/
IS			=	ft_isalnum \
				ft_isalpha ft_isascii ft_isdigit \
				ft_isprint

LST_DIR		=	lst/
LST			=	ft_lstnew ft_lstadd_front ft_lstsize \
				ft_lstlast ft_lstadd_back ft_lstdelone \
				ft_lstclear ft_lstiter ft_lstmap

MEM_DIR		=	mem/
MEM			=	ft_memcmp ft_memcpy ft_memmove \
				ft_memset ft_bzero ft_calloc

PRINTF_DIR	=	printf/
PRINTF		=	ft_printf ft_printffunc ft_printffunc2

PUT_DIR		=	put/
PUT			=	ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd

STR_DIR		=	str/
STR			=	ft_split ft_strchr \
				ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen \
				ft_strmapi ft_strncmp ft_strnstr \
				ft_strrchr ft_strtrim ft_substr	\
				ft_atoi ft_itoa

TO_DIR		=	to/
TO			=	ft_tolower ft_toupper

SRC_FILES	+=	$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES	+=	$(addprefix $(IS_DIR),$(IS))
SRC_FILES	+=	$(addprefix $(LST_DIR),$(LST))
SRC_FILES	+=	$(addprefix $(MEM_DIR),$(MEM))
SRC_FILES	+=	$(addprefix $(PRINTF_DIR),$(PRINTF))
SRC_FILES	+=	$(addprefix $(PUT_DIR),$(PUT))
SRC_FILES	+=	$(addprefix $(STR_DIR),$(STR))
SRC_FILES	+=	$(addprefix $(TO_DIR),$(TO))

SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
				$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(IS_DIR)
			@mkdir -p $(OBJ_DIR)$(MEM_DIR)
			@mkdir -p $(OBJ_DIR)$(PUT_DIR)
			@mkdir -p $(OBJ_DIR)$(TO_DIR)
			@mkdir -p $(OBJ_DIR)$(STR_DIR)
			@mkdir -p $(OBJ_DIR)$(LST_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
			@touch $(OBJF)

clean:
		$(RM) -r $(OBJ_DIR)
		$(RM) $(OBJF)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
