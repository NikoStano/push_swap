# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 07:51:02 by nistanoj          #+#    #+#              #
#    Updated: 2025/09/11 21:42:16 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

HEADER		=	includes

LIBFT		=	libft/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(HEADER) -ggdb
COMPILE		=	$(CC) $(CFLAGS)
RM			=	rm -rf
# CFLAGS 		+=	-fsanitize=address -g

SRCS_DIR	=	srcs/
OP_DIR		=	$(SRCS_DIR)op/
SORT_DIR	=	$(SRCS_DIR)sort/
UTILS_DIR	=	$(SRCS_DIR)utils/
SRCS		=	$(OP_DIR)op_one.c \
				$(OP_DIR)op_stack.c \
				$(OP_DIR)op_three.c \
				$(OP_DIR)op_two.c \
				$(SORT_DIR)sort_heavy.c \
				$(SORT_DIR)sort_small.c \
				$(SORT_DIR)sort_utils.c \
				$(UTILS_DIR)list_utils.c \
				$(UTILS_DIR)stack.c \
				$(UTILS_DIR)utils.c \
				$(SRCS_DIR)push_swap.c
DIR_OBJ		=	obj/
OBJS		=	$(SRCS:%.c=$(DIR_OBJ)%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "Linked into executable :\n\033[1;32m$(NAME)\033[0m"
	@echo "\033[1;32m>>> Use ./push_swap <numbers to sort> <<<\033[0m"

$(LIBFT_A):
	@make -s -C $(LIBFT)

$(DIR_OBJ)%.o:			%.c
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@
# 	@echo "Compiling \033[1;32m$<\033[0m."

norminette:
# 	@python3 -m norminette
	@norminette
	@echo "\033[1;32mNorminette check completed.\033[0m"

clean:
	@make clean -s -C $(LIBFT)
	@$(RM) $(DIR_OBJ)
	@echo "\033[1;32mOBJ file removed.\033[0m"

fclean:			clean
	@make fclean -s -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "\033[1;32mExecutable file removed.\033[0m"

re:				fclean all

bonus:			all

test: $(NAME)
	@echo "$(BLUE)--- Testing push_swap ---$(NO_COLOR)"
	@echo "$(BLUE)Test with 5 numbers: $(NO_COLOR)"
	@./$(NAME) 3 1 2 5 4
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker_linux "$$ARG"
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker_linux "$$ARG"
	@echo ""
	@echo "$(BLUE)--- Tests complete ---$(NO_COLOR)"

.PHONY:			all norminette clean fclean re bonus test
