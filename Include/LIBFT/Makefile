# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dparada <dparada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 11:56:30 by dparada           #+#    #+#              #
#    Updated: 2024/12/26 15:33:32 by dparada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
RED		= \033[31;1m

SOURCE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_memcmp.c ft_strlcpy.c ft_strlen.c \
		ft_strncmp.c  ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_strlcat.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_substr.c\
		ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		ft_strcmp.c ft_strlen_matrix.c ft_isspace.c ft_printf_fd.c \
		ft_print_matrix.c ft_first_char.c

SOURCE_P = ft_printf.c ft_putchar.c ft_hexa.c ft_itoa_u.c ft_itoa_p.c\
			ft_printf_utils.c ft_punt.c ft_putchar.c\

SOURCE_G = get_next_line_tobi.c get_next_line_tobi_utils.c\

OBJ = $(SOURCE:.c=.o)
OBJ_G = $(SOURCE_G:.c=.o)
OBJ_P = $(SOURCE_P:.c=.o)

all: $(NAME) gnl printf

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Compiling: $(RESET)libft."
		
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
gnl: $(OBJ_G)
	@ar rcs $(NAME) $(OBJ_G)
	
printf: $(OBJ_P)
	@ar rcs $(NAME) $(OBJ_P)
	
clean:
	@rm -frf $(OBJ) $(OBJ_G) $(OBJ_P)
	@echo "$(RED)Cleaning objects.$(RESET)"

fclean: clean
	@rm -frf $(NAME) printf gnl
	@echo "$(RED)Libreria cleaned.$(RESET)"
		
re: fclean all
	@echo "$(YELLOW)Libreria recompiled.$(RESET)"

.PHONY: all printf gnl clean fclean re