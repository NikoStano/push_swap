# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 07:51:02 by nistanoj          #+#    #+#              #
#    Updated: 2025/12/10 06:00:22 by nistanoj         ###   ########.fr        #
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

GREEN		=	\033[0;32m
L_GREEN		=	\033[1;32m
BLUE		=	\033[0;34m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
CYAN		=	\033[0;36m
L_GREEN		=	\033[0;32m
RESET		=	\033[0m

all:			$(NAME)

$(NAME):		$(COMMON_OBJS) $(GLOBAL_OBJS) $(LIBFT_A)
	@echo "$(CYAN)[ → ] Linking $(BOLD)$(NAME)...$(RESET)"
	@$(COMPILE) $(COMMON_OBJS) $(GLOBAL_OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)[ ✓ ] $(BOLD)$(NAME) compiled successfully!$(RESET)"
	@echo "$(GREEN)>>> Use ./push_swap <args> <<<$(RESET)"

bonus:			all $(BONUS_NAME)

$(BONUS_NAME):	$(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT_A)
	@echo "$(CYAN)[ → ] Linking $(BOLD)$(NAME)...$(RESET)"
	@$(COMPILE) $(COMMON_OBJS) $(BONUS_OBJS) -L$(LIBFT) -lft -o $(BONUS_NAME)
	@echo "$(GREEN)[ ✓ ] $(BOLD)$(BONUS_NAME) compiled successfully!$(RESET)"
	@echo "$(GREEN)>>> Use ./push_swap <args> | ./checker <args> <<<$(RESET)"


$(LIBFT_A): $(LIBFT)*.c $(LIBFT)*.h $(LIBFT)Makefile
	@$(MAKE) -s -C $(LIBFT) all

$(DIR_OBJ)%.o:			%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[ ℹ ] Compiling $<...$(RESET)"
	@$(COMPILE) -c $< -o $@

norminette:
	@echo "$(CYAN)[ → ] Running norminette $(BOLD)BY NISTANOJ...$(RESET)"
	@if command -v norminette > /dev/null 2>&1; then \
		NORM_CMD="norminette"; \
	elif command -v python3 -m norminette > /dev/null 2>&1; then \
		NORM_CMD="python3 -m norminette"; \
	else \
		echo "$(RED)[ ✗ ] Norminette is not installed.$(RESET)"; \
		echo "$(CYAN)[ ℹ ] Norminette check uncompleted.$(RESET)"; \
		exit 1; \
	fi; \
	TARGET="$(filter-out $@,$(MAKECMDGOALS))"; \
	if [ -z "$$TARGET" ]; then \
		TARGET="."; \
	else \
		echo "$(YELLOW)[ ℹ ] Checking target(s): $(BOLD)$$TARGET$(RESET)"; \
	fi; \
	OUTPUT=$$($$NORM_CMD $$TARGET 2>&1) ; \
	OUTPUT=$$(echo "$$OUTPUT" | sed '/Setting locale/d'); \
	ERRORS=$$(echo "$$OUTPUT" | grep "Error:"); \
	NOTICES=$$(echo "$$OUTPUT" | grep "Notice:"); \
	if [ -n "$${ERRORS}" ]; then \
		echo "$$OUTPUT" | grep -v ": OK!"; \
		echo "$(RED)[ ✗ ] Norminette found errors !$(RESET)"; \
	elif [ -n "$${NOTICES}" ]; then \
		echo "$$OUTPUT" | grep -v ": OK!"; \
		echo "$(YELLOW)[ ⚠ ] Norminette passed with notices.$(RESET)"; \
	else \
		echo "$(GREEN)[ ✓ ] Norminette $(BOLD)passed !$(RESET)"; \
	fi;

clean:
	@echo "$(RED)[🧹 ] Cleaning object files...$(RESET)"
	@make clean -s -C $(LIBFT)
	@$(RM) $(DIR_OBJ)

fclean:			clean
	@echo "$(RED)[🧹 ] Cleaning executable...$(RESET)"
	@make fclean -s -C $(LIBFT)
	@$(RM) $(NAME) $(BONUS_NAME)

re:				fclean all

tester:
	@echo "$(YELLOW)╔═══════════════════════════════════╗$(RESET)"
	@echo "$(YELLOW)║>>> Launching test on Push_Swap <<<║$(RESET)"
	@echo "$(YELLOW)╚═══════════════════════════════════╝$(RESET)"
	@echo "$(CYAN)[ → ] Cloning push_swap_tester...$(RESET)"
	@git clone -q https://github.com/NikoStano/push_swap_tester.git
	@cat push_swap_tester/test_ps.sh > test_ps.sh
	@chmod +x test_ps.sh
	@rm -rf push_swap_tester
	@echo "$(GREEN)[ ✓ ] push_swap_tester cloned successfully!$(RESET)"
	@echo "$(CYAN)→ Running all tests...$(RESET)"
	@make -s norminette
	@./test_ps.sh || true
	@echo "$(CYAN)[ ✓ ] All tests ran! Cleaning up...$(RESET)"
	@$(MAKE) -s fclean
	@rm -f test_ps.sh
	@echo "$(L_GREEN)[ ✓ ] All tests completed$(RESET)"

test: bonus $(NAME)
	@echo "$(YELLOW)--- Testing push_swap ---$(RESET)"
	@echo "$(BLUE)Test with 5 numbers: $(RESET)"
	@./$(NAME) 3 1 2 5 4
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers (operations count):$(RESET)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 100 random numbers and checker:$(RESET)"
	@ARG=$$(shuf -i 0-99 -n 100 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker "$$ARG"
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers (operations count):$(RESET)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | grep -v "DEBUG" | wc -l
	@echo ""
	@echo "$(BLUE)Test with 500 random numbers and checker:$(RESET)"
	@ARG=$$(shuf -i 0-499 -n 500 | tr '\n' ' '); \
	./$(NAME) "$$ARG" | ./checker "$$ARG"
	@echo ""
	@echo "$(GREEN)--- Tests complete ---$(RESET)"

.PHONY:			all norminette clean fclean re bonus test
