# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 19:03:41 by nistanoj          #+#    #+#              #
#    Updated: 2025/07/09 08:11:20 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
HEADER			=	push_swap.h

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
COMPILE			=	$(CC) $(CFLAGS)

SRCS			=	src/push_swap.c src/ops.c src/utils.c /
					src/chunks.c src/small_sort.c src/stack.c
OBJS			=	$(SRCS:.c=.o)

LIB_DIR			=	./libft
LIB				=	$(LIB_DIR)/libft.a

all		:	$(NAME) $(LIB)

$(LIB)	:
	@make -C $(LIB_DIR)

$(NAME)	:	$(OBJS) $(LIB)
	@$(COMPILE) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)

%.o:	%.c $(HEADER)
	@$(COMPILE) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	@make clean -C $(LIB_DIR)

fclean	:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re		:	fclean all

.PHONY	:	all clean re fclean
