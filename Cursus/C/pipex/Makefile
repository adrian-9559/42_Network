# Name of the executable
NAME = pipex

# Compiler and flags
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = trash_objects
TRASH_OBJECTS_DIR = trash_objects
UTILS_PIPEX_DIR = utils
LIB_DIR = lib

# NAME lib
LIB_NAME = $(LIB_DIR)/lib.a

# Files
MAIN_PROGRAM = \
	main.c

## Pipex
MAIN_SOURCE = \
	$(MAIN_PROGRAM) \
	$(SRC_DIR)/ft_pipex.c \

## Pipex utils
UTILS_PIPEX_SOURCES = \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_exec_cmd.c \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_pipex_cleanup.c \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_pipex_init.c \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_open_infile.c \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_open_outfile.c \
	$(SRC_DIR)/$(UTILS_PIPEX_DIR)/ft_pipex_utils.c

MAIN_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(MAIN_SOURCE:.c=.o)))
UTILS_PIPEX_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS_PIPEX_SOURCES:.c=.o)))

all: $(NAME) $(LIB_NAME)
	@echo "\033[36mEl ejecutable '$(NAME)' está lista para usarse.\033[0m"

$(NAME): $(MAIN_OBJECTS) $(UTILS_PIPEX_OBJECTS) $(LIB_NAME)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MAIN_OBJECTS) $(UTILS_PIPEX_OBJECTS) $(LIB_NAME) -o $(NAME) \
		&& echo "\033[32mCompilación finalizada correctamente.\033[0m" \
		|| echo "\033[31mError durante la compilación.\033[0m"
	@chmod 755 $(NAME)

$(LIB_NAME):
	@$(MAKE) -C $(LIB_DIR)

# Pattern rule for object files in OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/$(UTILS_PIPEX_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(MAIN_OBJECTS)
	@rm -rf $(TRASH_OBJECTS_DIR)
	@make -C $(LIB_DIR) clean
	@if [ $$? -eq 0 ]; then \
        echo "\033[32mArchivos objeto y carpeta '$(TRASH_OBJECTS_DIR)' eliminados correctamente.\033[0m"; \
    else \
        echo "\033[31mError al eliminar los archivos objeto o la carpeta.\033[0m"; \
    fi

fclean: 
	@rm -f $(MAIN_OBJECTS)
	@rm -rf $(TRASH_OBJECTS_DIR)
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)
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
