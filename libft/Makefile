# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 16:35:06 by nistanoj          #+#    #+#              #
#    Updated: 2025/05/20 19:30:55 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                              CONFIGURATION                                   #
#==============================================================================#

NAME			=	libft.a
INCLUDE			=	$(wildcard includes/*.h)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -Iincludes/.
COMPILE			=	$(CC) $(CFLAGS)


OBJ_DIR			=	obj
SRCS			=	$(FNCT) $(LIST) $(PRINTF) $(GNL)
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
FILE			=	*.c
RM				=	rm -rf

#==============================================================================#
#                                      SRCS                                    #
#==============================================================================#


FNCT			=	$(wildcard srcs/*.c)

LIST			=	$(wildcard lst/*.c)

PRINTF			=	$(wildcard ft_printf/*.c)

GNL				=	$(wildcard gnl/*.c)


FNCT			=	srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_isalnum.c srcs/ft_isalpha.c \
					srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_strchr.c srcs/ft_strdup.c \
					srcs/ft_strlcat.c srcs/ft_strlcpy.c srcs/ft_strlen.c srcs/ft_strncmp.c srcs/ft_strnstr.c \
					srcs/ft_strrchr.c srcs/ft_tolower.c srcs/ft_toupper.c srcs/ft_memset.c srcs/ft_putchar_fd.c \
					srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c srcs/ft_memcpy.c srcs/ft_memmove.c \
					srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_strjoin.c srcs/ft_split.c srcs/ft_itoa.c \
					srcs/ft_substr.c srcs/ft_strtrim.c srcs/ft_strmapi.c srcs/ft_striteri.c srcs/ft_isspace.c \

LIST			=	lst/ft_lstnew.c lst/ft_lstadd_front.c lst/ft_lstsize.c lst/ft_lstlast.c lst/ft_lstadd_back.c \
					lst/ft_lstdelone.c lst/ft_lstclear.c lst/ft_lstiter.c lst/ft_lstmap.c \

PRINTF			=	ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr_unsigned.c \
					ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putstr.c \

GNL				=	gnl/get_next_line.c gnl/get_next_line_utils.c \

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

GREEN			=	\033[0;32m
BLEU			=	\033[0;34m
RED				=	\033[0;31m
NC				=	\033[0m

#==============================================================================#
#                                    OPTION                                    #
#==============================================================================#

all		:	$(NAME)
	@echo "$(GREEN)\nLibft compiled successfully ✅$(NC)"

$(NAME)	:	$(OBJS)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o:	%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(COMPILE) -o $@ -c $<

clean	:
	@$(RM) $(OBJS)
	@$(RM) $(OBJ_DIR)

fclean	:	clean
	@$(RM) $(NAME)
	@echo "$(GREEN)\nAll Cleaned ✅$(NC)"

re		:	fclean all

run		:	all
	@echo "$(BLEU)\n Running test ...$(NC)"
	@$(COMPILE) $(FILE) -L. -lft -o test
	@./test
	@$(RM) test
	@echo "$(GREEN)\n✅ Test Cleaned ✅$(NC)"

.PHONY	:	all clean fclean re