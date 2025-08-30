# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 11:13:09 by adriescr          #+#    #+#              #
#    Updated: 2025/08/30 14:29:38 by adriescr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Directories
LIB_DIR = lib
LIB_PROJECT_DIR = lib_project
LIB_PROJECT_CHECKERS_DIR = $(LIB_PROJECT_DIR)/checkers
LIB_PROJECT_GENERATE_MAP_DIR = $(LIB_PROJECT_DIR)/generate_map
LIB_PROJECT_FILE_UTILS_DIR = $(LIB_PROJECT_DIR)/file_utils
LIB_PROJECT_MAP_UTILS_DIR = $(LIB_PROJECT_DIR)/map_utils
LIB_GAME_DIR = $(LIB_PROJECT_DIR)/game
LIB_MLX_DIR = $(LIB_DIR)/mlx

# Libraries
LIB_NAME = $(LIB_DIR)/lib.a
LIB_PROJECT_NAME = $(LIB_PROJECT_DIR)/lib_project.a
LIB_MLX_NAME = $(LIB_MLX_DIR)/libmlx.a

# Compiler and flags
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -w -g
MINI_LIB_FLAGS = -I$(LIB_MLX_DIR) -L$(LIB_MLX_DIR) -lmlx -framework OpenGL -framework AppKit -w

# Source files
MY_SOURCES = \
	main.c

PROJECT_CHECKERS_RESOURCE = \
	$(LIB_PROJECT_CHECKERS_DIR)/arguments/ft_checker_name_arg.c \
	$(LIB_PROJECT_CHECKERS_DIR)/arguments/ft_checker_num_arg.c \
	$(LIB_PROJECT_CHECKERS_DIR)/file/ft_checker_file.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_map_empty.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_map.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_figure.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_wall.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_requirements.c \
	$(LIB_PROJECT_CHECKERS_DIR)/map/ft_checker_map_posible.c

PROJECT_GENERATE_MAP_RESOURCE = \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate.c \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate_file.c \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate_file_utils.c \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate_map.c \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate_simple_map.c \
	$(LIB_PROJECT_GENERATE_MAP_DIR)/ft_generate_map_utils.c

PROJECT_FILE_UTILS_RESOURCE = \
	$(LIB_PROJECT_FILE_UTILS_DIR)/ft_get_map_file.c

PROJECT_MAP_UTILS_RESOURCE = \
	$(LIB_PROJECT_MAP_UTILS_DIR)/ft_free_map.c \
	$(LIB_PROJECT_MAP_UTILS_DIR)/ft_realloc_map.c \
	$(LIB_PROJECT_MAP_UTILS_DIR)/ft_show_map.c \
	$(LIB_PROJECT_MAP_UTILS_DIR)/ft_small_map.c

MY_LIB_PROJECT_SOURCES = \
	$(LIB_GAME_DIR)/ft_game.c \
	$(LIB_GAME_DIR)/ft_start_game.c \
	$(LIB_GAME_DIR)/ft_close_game.c \
	$(LIB_GAME_DIR)/img/ft_load_textures.c \
	$(LIB_GAME_DIR)/mlx/img/ft_init_mlx_textures.c \
	$(LIB_GAME_DIR)/mlx/img/ft_print_mlx_image.c \
	$(LIB_GAME_DIR)/collectibles/ft_find_total_collectibles.c \
	$(LIB_GAME_DIR)/player/ft_move_player.c \
	$(LIB_GAME_DIR)/player/ft_set_player_position.c \
	$(LIB_GAME_DIR)/player/ft_find_player.c

MY_LIB = \
	$(LIB_DIR)/ft_is_digit.c \
	$(LIB_DIR)/ft_putstr.c \
	$(LIB_DIR)/ft_putstr_error.c \
	$(LIB_DIR)/ft_putchar_error.c \
	$(LIB_DIR)/ft_putchar.c \
	$(LIB_DIR)/ft_is_number.c \
	$(LIB_DIR)/ft_atoi.c \
	$(LIB_DIR)/ft_split.c \
	$(LIB_DIR)/ft_count_words.c \
	$(LIB_DIR)/ft_memcpy.c \
	$(LIB_DIR)/ft_strlen.c \
	$(LIB_DIR)/ft_strdup.c \
	$(LIB_DIR)/ft_strjoin.c \
	$(LIB_DIR)/ft_substr.c \
	$(LIB_DIR)/ft_strchr.c \
	$(LIB_DIR)/ft_strcmp.c \
	$(LIB_DIR)/ft_rand.c \
	$(LIB_DIR)/ft_file_utils.c \
	$(LIB_DIR)/get_next_line/get_next_line.c

# Project resources
MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_LIB_OBJECTS = $(MY_LIB:.c=.o)
MY_LIB_PROJECT_OBJECTS = $(MY_LIB_PROJECT_SOURCES:.c=.o)
PROJECT_CHECKERS_RESOURCE_OBJECTS = $(PROJECT_CHECKERS_RESOURCE:.c=.o)
PROJECT_GENERATE_MAP_RESOURCE_OBJECTS = $(PROJECT_GENERATE_MAP_RESOURCE:.c=.o)
PROJECT_FILE_UTILS_RESOURCE_OBJECTS = $(PROJECT_FILE_UTILS_RESOURCE:.c=.o)
PROJECT_MAP_UTILS_RESOURCE_OBJECTS = $(PROJECT_MAP_UTILS_RESOURCE:.c=.o)

# Targets
all: $(NAME) $(LIB_NAME) $(LIB_PROJECT_NAME) $(LIB_MLX_NAME)
	@echo "\033[36mEl ejecutable '$(NAME)' está listo para usarse.\033[0m"

# Compile the main project
$(LIB_PROJECT_NAME): $(MY_LIB_PROJECT_OBJECTS) \
	$(PROJECT_CHECKERS_RESOURCE_OBJECTS) \
	$(PROJECT_GENERATE_MAP_RESOURCE_OBJECTS) \
	$(PROJECT_FILE_UTILS_RESOURCE_OBJECTS) \
	$(PROJECT_MAP_UTILS_RESOURCE_OBJECTS)
	@echo "\033[34mCompilando lib_project/game...\033[0m"
	@echo "\033[34mCompilando lib_project/checkers...\033[0m"
	@echo "\033[34mCompilando lib_project/generate_map...\033[0m"
	@echo "\033[34mCompilando lib_project/file_utils...\033[0m"
	@echo "\033[34mCompilando lib_project/map_utils...\033[0m"
	@echo "\033[34mCompilando lib_project...\033[0m"
		@$(AR) $(LIB_PROJECT_NAME) $(MY_LIB_PROJECT_OBJECTS) \
			$(PROJECT_CHECKERS_RESOURCE_OBJECTS) \
			$(PROJECT_GENERATE_MAP_RESOURCE_OBJECTS) \
			$(PROJECT_FILE_UTILS_RESOURCE_OBJECTS) \
			$(PROJECT_MAP_UTILS_RESOURCE_OBJECTS)

# Compile the miniLibX library
$(LIB_MLX_NAME):
	@echo "\033[34mCompilando miniLibX...\033[0m"
	@$(MAKE) -C $(LIB_MLX_DIR)

# Compile the library
$(LIB_NAME): $(MY_LIB_OBJECTS)
	@echo "\033[34mCompilando lib...\033[0m"
	@$(AR) $(LIB_NAME) $(MY_LIB_OBJECTS)

# Compile the main executable
$(NAME): $(MY_OBJECTS) $(LIB_NAME) $(LIB_PROJECT_NAME) $(LIB_MLX_NAME)
	@echo "\033[34mCompilando so_long...\033[0m"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB_NAME) $(LIB_PROJECT_NAME) $(MINI_LIB_FLAGS) -o $(NAME)
	@chmod 755 $(NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mCompilación finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la compilación.\033[0m"; \
	fi

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

lib/%.o: lib/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

lib_project/%.o: lib_project/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

lib/mlx/%.o: lib/mlx/%.c
	@$(CC) $(MINI_LIB_FLAGS) -c $< -o $@

# Clean up object files
clean:
	@rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) \
		$(MY_LIB_PROJECT_OBJECTS) \
		$(PROJECT_CHECKERS_RESOURCE_OBJECTS) \
		$(PROJECT_GENERATE_MAP_RESOURCE_OBJECTS) \
		$(PROJECT_FILE_UTILS_RESOURCE_OBJECTS) \
		$(PROJECT_MAP_UTILS_RESOURCE_OBJECTS) \
		$(LIB_MLX_DIR)/*.o
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mArchivos objeto eliminados correctamente.\033[0m"; \
	else \
		echo "\033[31mError al eliminar los archivos objeto.\033[0m"; \
	fi

# Clean up the library and project library
fclean:
	@rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) \
		$(MY_LIB_PROJECT_OBJECTS) \
		$(PROJECT_CHECKERS_RESOURCE_OBJECTS) \
		$(PROJECT_GENERATE_MAP_RESOURCE_OBJECTS) \
		$(PROJECT_FILE_UTILS_RESOURCE_OBJECTS) \
		$(PROJECT_MAP_UTILS_RESOURCE_OBJECTS) \
		$(LIB_MLX_DIR)/*.o
	@rm -f $(NAME) $(LIB_NAME) $(LIB_PROJECT_NAME)
	@rm -f $(LIB_MLX_NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mLimpieza completa realizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError al realizar la limpieza completa.\033[0m"; \
	fi

# Rebuild everything
re: fclean
	@echo "\033[34mRecompilando todo...\033[0m"
	@$(MAKE) --always-make all
	@if [ $$? -eq 0 ]; then \
		echo "\033[35mRecompilación finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la recompilación.\033[0m"; \
	fi

# Phony targets
.PHONY: all clean fclean re
