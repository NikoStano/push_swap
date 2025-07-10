# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 19:03:41 by nistanoj          #+#    #+#              #
#    Updated: 2025/07/09 13:04:23 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   push_swap
HEADER          =   push_swap.h

CC              =   cc
CFLAGS          =   -Wall -Werror -Wextra -I.

SRCS            =   src/push_swap.c src/ops.c src/utils.c src/utils2.c \
                    src/chunks.c src/small_sort.c src/stack.c src/ops2.c
OBJS            =   $(SRCS:.c=.o)

all:            $(NAME)
	@echo "Makefile as compile succefully !"

$(NAME):        $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:    %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
