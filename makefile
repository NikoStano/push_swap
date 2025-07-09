# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 19:03:41 by nistanoj          #+#    #+#              #
#    Updated: 2025/07/09 09:20:47 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME			=	push_swap
# HEADER			=	push_swap.h

# CC				=	cc
# CFLAGS			=	-Wall -Werror -Wextra -I.
# LFLAGS			=	-L$(LIB_DIR) -lft -lm

# SRCS			=	src/push_swap.c src/ops.c src/utils.c \
# 					src/chunks.c src/small_sort.c src/stack.c
# OBJS			=	$(SRCS:.c=.o)

# LIB_DIR			=	./libft
# LIB				=	$(LIB_DIR)/libft.a

# all		:	$(NAME) $(LIB)

# $(LIB)	:
# 	@make -C $(LIB_DIR)

# $(NAME)	:	$(OBJS) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

# %.o:	%.c $(HEADER)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean	:
# 	@rm -f $(OBJS)
# 	@make clean -C $(LIB_DIR)

# fclean	:	clean
# 	@rm -f $(NAME)
# 	@make fclean -C $(LIB_DIR)

# re		:	fclean all

# .PHONY	:	all clean fclean re

NAME            =   push_swap
CHECKER         =   checker
CHECKER_BIN		=	checker_linux

HEADER          =   push_swap.h

CC              =   cc
CFLAGS          =   -Wall -Werror -Wextra -I.
LFLAGS          =   -L$(LIB_DIR) -lft -lm

SRCS            =   src/push_swap.c src/ops.c src/utils.c \
                    src/chunks.c src/small_sort.c src/stack.c
OBJS            =   $(SRCS:.c=.o)

CHECKER_SRCS    =   checker_linux.c src/ops.c src/utils.c src/stack.c
CHECKER_OBJS    =   $(CHECKER_SRCS:.c=.o)

LIB_DIR         =   ./libft
LIB             =   $(LIB_DIR)/libft.a

all:            $(NAME) $(CHECKER) $(LIB)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME):        $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(CHECKER):     $(CHECKER_BIN)
	@cp $< $@
	@chmod +x $@

%.o:    %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(CHECKER_OBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make fclean -C $(LIB_DIR)

re:     fclean all

.PHONY: all clean fclean re
