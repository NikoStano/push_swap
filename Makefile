# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 07:51:02 by nistanoj          #+#    #+#              #
#    Updated: 2025/09/05 18:42:55 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

HEADER		=	includes

LIBFT		=	libft/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(HEADER)
COMPILE		=	$(CC) $(CFLAGS)
RM			=	rm -rf
# CFLAGS 		+=	-fsanitize=address -g

SRCS_DIR	=	srcs/
SRCS		=	$(SRCS_DIR)op/op_one.c \
				$(SRCS_DIR)op/op_stack.c \
				$(SRCS_DIR)op/op_three.c \
				$(SRCS_DIR)op/op_two.c \
				$(SRCS_DIR)sort/sort_heavy.c \
				$(SRCS_DIR)sort/sort_small.c \
				$(SRCS_DIR)utils/init_stack.c \
				$(SRCS_DIR)utils/list_index.c \
				$(SRCS_DIR)utils/list_utils.c \
				$(SRCS_DIR)push_swap.c
OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "Linked into executable \033[1;32m$(NAME)\033[0m."

$(LIBFT_A):
	@make -s -C $(LIBFT)

.c.o:
	@$(COMPILE) -c $< -o $(<:.c=.o)
	@echo "Compiling \033[1;32m$<\033[0m."

norminette:
	@norminette $(SRCS) $(HEADER) $(LIBFT)
	@echo "\033[1;32mNorminette check completed.\033[0m"

clean:
	@make clean -s -C $(LIBFT)
	@$(RM) $(OBJS)
	@echo "\033[1;32mOBJ file removed.\033[0m"

fclean:			clean
	@make fclean -s -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "\033[1;32mExecutable removed.\033[0m"

re:				fclean all

bonus:			all

.PHONY:			all norminette clean fclean re bonus
