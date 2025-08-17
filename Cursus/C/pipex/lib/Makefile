# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: adriescr <adriescr@student.42madrid.com	+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2025/08/17 15:13:37 by adriescr		  #+#	#+#			  #
#	Updated: 2025/08/17 15:43:33 by adriescr		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

# Name of the executable
NAME = lib

# Compiler and flags
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

# Directories
## CMD DIR
CMD_DIR = cmd
## File DIR
FILE_DIR = files
## Trash_Objects DIR
TRASH_OBJECTS_DIR = trash_objects
### Set output directory for object files
OBJDIR = $(TRASH_OBJECTS_DIR)

# Files
LIB_SOURCES = \
	ft_count_words.c \
	ft_isspace.c \
	ft_memmove.c \
	ft_print.c \
	ft_skip_whitespace.c \
	ft_split.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_trim_quotes.c \
	ft_unescape_quotes.c \

## CMD sources
CMD_SOURCES = \
	$(CMD_DIR)/ft_arg_len.c \
	$(CMD_DIR)/ft_count_args.c \
	$(CMD_DIR)/ft_extract_path.c \
	$(CMD_DIR)/ft_get_cmd_path.c \
	$(CMD_DIR)/ft_get_next_arg.c \
	$(CMD_DIR)/ft_search_cmd_in_paths.c \
	$(CMD_DIR)/ft_skip_argument.c \
	$(CMD_DIR)/ft_split_shell.c

## FILE sources
FILE_SOURCES = \
	$(FILE_DIR)/ft_open_fd.c

# Object files
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)
CMD_OBJECTS = $(CMD_SOURCES:.c=.o)
FILE_OBJECTS = $(FILE_SOURCES:.c=.o)

# All sources and objects
SOURCES = $(LIB_SOURCES) $(CMD_SOURCES) $(FILE_SOURCES)
OBJECTS = $(LIB_OBJECTS) $(CMD_OBJECTS) $(FILE_OBJECTS)

# Default target
all: $(NAME)
	@echo "\033[36mLa biblioteca '$(NAME)' está lista para usarse.\033[0m"

# Change object file paths to be inside OBJDIR
LIB_OBJECTS = $(addprefix $(OBJDIR)/, $(LIB_SOURCES:.c=.o))
CMD_OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(CMD_SOURCES:.c=.o)))
FILE_OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(FILE_SOURCES:.c=.o)))
OBJECTS = $(LIB_OBJECTS) $(CMD_OBJECTS) $(FILE_OBJECTS)

# Create OBJDIR if not exists and build static library
$(NAME): $(OBJECTS)
	@mkdir -p $(OBJDIR)
	@echo "\033[34mCompilando $(NAME).a...\033[0m"
	@$(AR) $(NAME).a $(OBJECTS)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mCompilación finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la compilación.\033[0m"; \
	fi

$(OBJDIR)/%.o: $(CMD_DIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(FILE_DIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(TRASH_OBJECTS_DIR)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mArchivos objeto y carpeta '$(TRASH_OBJECTS_DIR)' de la libreria eliminados correctamente.\033[0m"; \
	else \
		echo "\033[31mError al eliminar los archivos objeto o la carpeta de la libreria.\033[0m"; \
	fi

fclean:
	@rm -f $(OBJECTS)
	@rm -rf $(TRASH_OBJECTS_DIR)
	@rm -f $(NAME).a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32mLimpieza de la libreria completa realizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError al realizar la limpieza completa de la libreria.\033[0m"; \
	fi

re: fclean
	@echo "\033[34mRecompilando todo...\033[0m"
	@$(MAKE) --always-make all
	@if [ $$? -eq 0 ]; then \
		echo "\033[35mRecompilación de la libreria finalizada correctamente.\033[0m"; \
	else \
		echo "\033[31mError durante la recompilación de la libreria.\033[0m"; \
	fi

.PHONY: all clean fclean re
