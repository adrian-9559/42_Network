# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:57:53 by adriescr          #+#    #+#              #
#    Updated: 2025/08/28 17:10:42 by adriescr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB_NAME = lib/lib.a
LIB_OPERATIONS_NAME = lib_operations/lib_operations.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -w

MY_SOURCES = \
	main.c \
	ft_checker.c \
	ft_stack.c \
	ft_stack_utils.c \
	push_swap.c \
	push_swap_utils.c \
	sort_functions.c \

MY_LIB = \
	lib/ft_is_digit.c \
	lib/ft_putstr.c \
	lib/ft_putstr_error.c \
	lib/ft_putchar_error.c \
	lib/ft_putchar.c \
	lib/ft_is_number.c \
	lib/ft_atoi.c \
	lib/ft_split.c \
	lib/ft_memcpy.c

MY_LIB_OPERATIONS = \
	lib_operations/ft_pa.c \
	lib_operations/ft_pb.c \
	lib_operations/ft_sa.c \
	lib_operations/ft_sb.c \
	lib_operations/ft_ss.c \
	lib_operations/ft_ra.c \
	lib_operations/ft_rb.c \
	lib_operations/ft_rr.c \
	lib_operations/ft_rra.c \
	lib_operations/ft_rrb.c \
	lib_operations/ft_rrr.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_LIB_OBJECTS = $(MY_LIB:.c=.o)
MY_LIB_OPERATIONS_OBJECTS = $(MY_LIB_OPERATIONS:.c=.o)

all: $(NAME) $(LIB_NAME) $(LIB_OPERATIONS_NAME)
	@echo "\033[36mEl ejecutable '$(NAME)' está listo para usarse.\033[0m"

$(LIB_NAME): $(MY_LIB_OBJECTS)
	@echo "\033[34mCompilando lib...\033[0m"
	@$(AR) $(LIB_NAME) $(MY_LIB_OBJECTS)

$(LIB_OPERATIONS_NAME): $(MY_LIB_OPERATIONS_OBJECTS)
	@echo "\033[34mCompilando lib_operations/...\033[0m"
	@$(AR) $(LIB_OPERATIONS_NAME) $(MY_LIB_OPERATIONS_OBJECTS)

$(NAME): $(MY_OBJECTS) $(LIB_NAME) $(LIB_OPERATIONS_NAME)
	@echo "\033[34mCompilando $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(MY_LIB_OBJECTS) $(LIB_NAME) $(LIB_OPERATIONS_NAME) -o $(NAME)
	@chmod 755 $(NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mCompilación finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la compilación.\033[0m"; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

lib/%.o: lib/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) $(MY_LIB_OPERATIONS_OBJECTS)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mArchivos objeto eliminados correctamente.\033[0m"; \
	else \
		echo "\033[31mError al eliminar los archivos objeto.\033[0m"; \
	fi

fclean: 
	@rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) $(MY_LIB_OPERATIONS_OBJECTS)
	@rm -f $(NAME) $(LIB_NAME) $(LIB_OPERATIONS_NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mLimpieza completa realizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError al realizar la limpieza completa.\033[0m"; \
	fi

re: fclean
	@echo "\033[34mRecompilando todo...\033[0m"
	@$(MAKE) --always-make all
	@if [ $$? -eq 0 ]; then \
		echo "\033[35mRecompilación finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la recompilación.\033[0m"; \
	fi

.PHONY: all clean fclean re
