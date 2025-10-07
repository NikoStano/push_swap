# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 07:51:02 by nistanoj          #+#    #+#              #
#    Updated: 2025/10/05 01:20:38 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS_NAME	=	checker

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
#SRCS COMMUNES
COMMON_SRCS	=	$(OP_DIR)op_stack.c \
				$(UTILS_DIR)list_utils.c \
				$(UTILS_DIR)stack.c \
				$(UTILS_DIR)utils.c \
				$(UTILS_DIR)common.c
#SRCS PUSH_SWAP
GLOBAL_SRCS	=	$(OP_DIR)op_one.c \
				$(OP_DIR)op_three.c \
				$(OP_DIR)op_two.c \
				$(SORT_DIR)sort_heavy.c \
				$(SORT_DIR)sort_small.c \
				$(SORT_DIR)sort_utils.c \
				$(SRCS_DIR)push_swap.c
BONUS_SRCS	=	$(SRCS_DIR)checker.c

DIR_OBJ		=	obj/
COMMON_OBJS	=	$(COMMON_SRCS:%.c=$(DIR_OBJ)%.o)
GLOBAL_OBJS	=	$(GLOBAL_SRCS:%.c=$(DIR_OBJ)%.o)
BONUS_OBJS	=	$(BONUS_SRCS:%.c=$(DIR_OBJ)%.o)

GREEN		=	\033[1;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
NO_COLOR	=	\033[0m

all:			$(NAME)

$(NAME):		$(COMMON_OBJS) $(GLOBAL_OBJS) $(LIBFT_A)
	@$(COMPILE) $(COMMON_OBJS) $(GLOBAL_OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME)$(NO_COLOR) created successfully.\n"
	@echo "$(GREEN)>>> Use ./push_swap <args> <<<\n$(NO_COLOR)"

bonus:			all $(BONUS_NAME)

$(BONUS_NAME):	$(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT_A)
	@$(COMPILE) $(COMMON_OBJS) $(BONUS_OBJS) -L$(LIBFT) -lft -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME)$(NO_COLOR) created successfully.\n"
	@echo "$(GREEN)>>> Use ./push_swap <args> | ./checker <args> <<<\n$(NO_COLOR)"


$(LIBFT_A): $(LIBFT)*.c $(LIBFT)*.h $(LIBFT)Makefile
	@$(MAKE) -s -C $(LIBFT) all

$(DIR_OBJ)%.o:			%.c
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@

norminette:
	@echo "$(CYAN)[ ℹ ] Running norminette...$(RESET)"
	@if command -v python3 >/dev/null 2>&1; then \
		OUTPUT=$$(python3 -m norminette 2>&1 | grep "Error"); \
		if [ -z "$$OUTPUT" ]; then \
			echo "$(GREEN)[ ✓ ] Norminette passed!$(RESET)"; \
		else \
			python3 -m norminette 2>&1 | grep -v "Norme: OK"; \
			echo "$(RED)[ ✗ ] Norminette found errors!$(RESET)"; \
		fi; \
	else \
		echo "$(RED)[ ✗ ] Norminette is not installed.$(RESET)"; \
	fi
	@echo "$(CYAN)[ ℹ ] Norminette check completed.$(RESET)"

clean:
	@make clean -s -C $(LIBFT)
	@$(RM) $(DIR_OBJ)
	@echo "$(GREEN)OBJ files removed.$(NO_COLOR)"

fclean:			clean
	@make fclean -s -C $(LIBFT)
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)Executable files removed.$(NO_COLOR)"

re:				fclean all

tester: $(NAME) norminette
	@echo "$(YELLOW)╔════════════════════════════════════╗$(RESET)"
	@echo "$(YELLOW)║    Launching test on Push_Swap     ║$(RESET)"
	@echo "$(YELLOW)╚════════════════════════════════════╝$(RESET)"
	@echo "$(CYAN)→ Cloning push_swap_tester...$(RESET)"
	@git clone -q https://github.com/NikoStano/push_swap_tester.git
	@cat push_swap_tester/test_ps.sh > test_ps.sh
	@chmod +x test_ps.sh
	@rm -rf push_swap_tester
	@echo "$(GREEN)✓ push_swap_tester cloned successfully!$(RESET)"
	@echo "$(CYAN)→ Running all tests...$(RESET)"
	@./test_ps.sh || true
	@echo "$(CYAN)✓ All tests ran! Cleaning up...$(RESET)"
	@$(MAKE) -s fclean
	@rm -f test_ps.sh
	@echo "$(L_GREEN)✓ All tests completed$(RESET)"

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

.PHONY:			all norminette clean fclean re bonus test
