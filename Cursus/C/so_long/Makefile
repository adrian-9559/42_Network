NAME = so_long
LIB_NAME = lib/lib.a
LIB_PROJECT_NAME = lib_project/lib_project.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = \
	main.c

MY_LIB_PROJECT_SOURCES = \
	lib_project/checkers/arguments/ft_checker_name_arg.c \
	lib_project/checkers/arguments/ft_checker_num_arg.c \
	lib_project/checkers/file/ft_checker_file.c \
	lib_project/checkers/map/ft_checker_map_empty.c \
	lib_project/checkers/map/ft_checker_map.c \
	lib_project/generate_map/ft_generate.c \
	lib_project/generate_map/ft_generate_file.c \
	lib_project/generate_map/ft_generate_file_utils.c \
	lib_project/generate_map/ft_generate_map.c \
	lib_project/generate_map/ft_generate_simple_map.c \
	lib_project/generate_map/ft_generate_map_utils.c \
	lib_project/file_utils/ft_get_map_file.c \
	lib_project/map_utils/ft_free_map.c \
	lib_project/map_utils/ft_realloc_map.c \
	lib_project/map_utils/ft_show_map.c

MY_LIB = \
	lib/ft_is_digit.c \
	lib/ft_putstr.c \
	lib/ft_putstr_error.c \
	lib/ft_putchar_error.c \
	lib/ft_putchar.c \
	lib/ft_is_number.c \
	lib/ft_atoi.c \
	lib/ft_split.c \
	lib/ft_count_words.c \
	lib/ft_memcpy.c \
	lib/ft_strlen.c \
	lib/ft_strdup.c \
	lib/ft_strjoin.c \
	lib/ft_substr.c \
	lib/ft_strchr.c \
	lib/ft_strcmp.c \
	lib/ft_rand.c \
	lib/ft_file_utils.c \
	lib/get_next_line/get_next_line.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_LIB_OBJECTS = $(MY_LIB:.c=.o)
MY_LIB_PROJECT_OBJECTS = $(MY_LIB_PROJECT_SOURCES:.c=.o)

all: $(NAME) $(LIB_NAME) $(LIB_PROJECT_NAME)

$(LIB_PROJECT_NAME): $(MY_LIB_PROJECT_OBJECTS)
	$(AR) $(LIB_PROJECT_NAME) $(MY_LIB_PROJECT_OBJECTS)

$(LIB_NAME): $(MY_LIB_OBJECTS)
	$(AR) $(LIB_NAME) $(MY_LIB_OBJECTS)

$(NAME): $(MY_OBJECTS) $(LIB_NAME) $(LIB_PROJECT_NAME)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB_NAME) $(LIB_PROJECT_NAME) -o $(NAME)
	chmod 755 $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@

lib_project/%.o: lib_project/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) $(MY_LIB_PROJECT_OBJECTS)

fclean: clean
	rm -f $(NAME) $(LIB_NAME) $(LIB_PROJECT_NAME)

re: fclean all
.PHONY: all clean fclean re
