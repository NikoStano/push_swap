# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 16:35:06 by nistanoj          #+#    #+#              #
#    Updated: 2025/09/30 16:54:00 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -ggdb
COMPILE		=	$(CC) $(CFLAGS)
RM			=	rm -rf

SRCS		=	ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strjoin.c \
				ft_split.c \
				ft_itoa.c \
				ft_substr.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_atoi_base.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_isspace.c\
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_strtol.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_nbr.c \
				ft_print_hex.c \
				ft_print_ptr.c \
				ft_printf.c \
				ft_free_sp.c \
 				get_next_line.c \
 				get_next_line_utils.c
DIR_OBJ		=	obj/
OBJ			=	$(SRCS:%.c=$(DIR_OBJ)%.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $@ $^
	@echo "\033[1;32m$(NAME)\033[0m created successfully."

$(DIR_OBJ)%.o:		%.c
	@mkdir -p $(DIR_OBJ)
	@$(COMPILE) -o $@ -c $<
	
clean:
	@$(RM) $(DIR_OBJ)
	@$(RM) $(OBJ)

fclean:		clean
	@$(RM) $(NAME)
	@echo "\033[1;32m$(NAME)\033[0m deleted."

re:			fclean all

.PHONY:	all clean fclean re
