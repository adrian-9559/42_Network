# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 17:04:19 by adriescr          #+#    #+#              #
#    Updated: 2025/09/30 13:04:08 by adriescr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME OF THE PROGRAM
NAME := philosophers

# COMPILER AND FLAGS
CC := cc
CFLAGS :=

# DIRECTORIES
SRC_DIR := src
OBJ_DIR := objs

# SOURCES
## Main source
MAIN_SRC := main.c

## UTILS
### Core
CORE_SRCS := \
	$(SRC_DIR)/ft_philosophers.c \
	$(SRC_DIR)/philosophers/ft_create_philosophers.c \
	$(SRC_DIR)/philosophers/ft_destroy_philosophers.c \
	$(SRC_DIR)/philosophers/ft_philo_routine.c \
	$(SRC_DIR)/philosophers/ft_print_status.c \
	$(SRC_DIR)/philosophers/ft_start_eating.c \
	$(SRC_DIR)/philosophers/ft_take_forks_and_eat.c \
	$(SRC_DIR)/philosophers/ft_spawn_philosophers.c \
	$(SRC_DIR)/philosophers/ft_monitor.c \

### Print sources
PRINT_SRCS := \
	$(SRC_DIR)/print/ft_putcolor.c \
	$(SRC_DIR)/print/ft_putstr.c \
	$(SRC_DIR)/print/ft_putchar.c \
	$(SRC_DIR)/print/ft_error.c \

### Data sources
DATA_SRCS := \
	$(SRC_DIR)/data/ft_construct_data.c \
	$(SRC_DIR)/data/ft_cleanup_data.c \

### Thread sources
THREAD_SRCS := \
	$(SRC_DIR)/thread/ft_create_thread.c \

### Mutex sources
MUTEX_SRCS := \
	$(SRC_DIR)/mutex/ft_init_mutexes.c \

### Forks sources
FORKS_SRCS := \
	$(SRC_DIR)/forks/ft_put_forks.c \
	$(SRC_DIR)/forks/ft_take_forks.c \

### Time sources
TIME_SRCS := \
	$(SRC_DIR)/time/ft_ms_sleep.c \
	$(SRC_DIR)/time/ft_now_ms.c \
	$(SRC_DIR)/time/ft_timeval_to_ms.c \

### Utils sources
UTILS_SRCS := \
	$(SRC_DIR)/utils/ft_atoi.c \
	$(SRC_DIR)/utils/ft_strlen.c \
	$(SRC_DIR)/utils/ft_strcmp.c \

## ALL sources
ALL_SRCS := \
	$(MAIN_SRC) \
	$(CORE_SRCS) \
	$(UTILS_SRCS) \
	$(DATA_SRCS) \
	$(THREAD_SRCS) \
	$(MUTEX_SRCS) \
	$(FORKS_SRCS) \
	$(TIME_SRCS) \
	$(PRINT_SRCS)

SRCS := $(ALL_SRCS)

OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

DEPS := $(OBJS:.o=.d)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "\033[0;31m[ERROR]\033[0m Compilación fallida en $<" && exit 1)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ && \
	echo "\033[0;32m[OK]\033[0m Compilado y listo para usar: $(NAME)" || \
	(echo "\033[0;31m[ERROR]\033[0m Fallo al enlazar $(NAME)" && exit 1)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

