# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 19:03:41 by nistanoj          #+#    #+#              #
#    Updated: 2025/05/20 19:35:02 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap.a
HEADER			=	push_swap.h
DIR_OBJ			=	obj

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
COMPILE			=	$(CC) $(CFLAGS)

SRCS			=	push_swap.c
OBJ				=	$(SRCS:.c=.o)

LIB				=	libft.a

all		:	$(NAME)

$(NAME)$(LIB)	:	$(OBJ) $(LIB)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o:	%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(COMPILE) -o $@ -c $<

clean	:
	rm -rf $(DIR_OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean re fclean