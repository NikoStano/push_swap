# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 07:51:02 by nistanoj          #+#    #+#              #
#    Updated: 2025/10/04 20:05:07 by nistanoj         ###   ########.fr        #
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
# CFLAGS 		+=	-fsanitize=address -ggdb

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

GREEN		=	\033[1;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
NO_COLOR	=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "Linked into executable :\npush_swap\n$(GREEN)$(NAME)$(NO_COLOR)"
	@echo "$(GREEN)>>> Use ./push_swap <numbers to sort> <<<$(NO_COLOR)"

$(LIBFT_A): $(LIBFT)*.c $(LIBFT)*.h $(LIBFT)Makefile
	@$(MAKE) -s -C $(LIBFT) all

$(DIR_OBJ)%.o:			%.c
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@
# 	@echo "Compiling \033[1;32m$<$(NO_COLOR)."

norminette:
	@echo "\$(BLUE)Norminette check :$(NO_COLOR)"
	@python3 -m norminette
# 	@norminette

clean:
	@make clean -s -C $(LIBFT)
	@$(RM) $(DIR_OBJ)
	@echo "$(GREEN)OBJ file removed.$(NO_COLOR)"

fclean:			clean
	@make fclean -s -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN)Executable file removed.$(NO_COLOR)"

re:				fclean all

bonus:			all

test: $(NAME)
	@echo "$(YELLOW)--- Testing push_swap ---$(NO_COLOR)"
	@echo "$(BLUE)Test with 5 numbers: $(NO_COLOR)"
	@./$(NAME) 3 1 2 5 4
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker "$$ARG"
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers (operations count):$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers and checker:$(NO_COLOR)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker "$$ARG"
	@echo ""
	@echo "$(GREEN)--- Tests complete ---$(NO_COLOR)"
	@make fclean -s

.PHONY:			all norminette clean fclean re bonus test
