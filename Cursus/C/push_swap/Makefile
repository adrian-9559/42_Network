NAME = push_swap
LIB_NAME = lib/lib.a
LIB_OPERATIONS_NAME = lib_operations/lib_operations.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = \
	main.c \
	ft_checker.c \
	ft_stack.c \
	ft_stack_utils.c \
	push_swap.c \
	push_swap_utils.c \

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

$(LIB_NAME): $(MY_LIB_OBJECTS)
	$(AR) $(LIB_NAME) $(MY_LIB_OBJECTS)

$(LIB_OPERATIONS_NAME): $(MY_LIB_OPERATIONS_OBJECTS)
	$(AR) $(LIB_OPERATIONS_NAME) $(MY_LIB_OPERATIONS_OBJECTS)

$(NAME): $(MY_OBJECTS) $(LIB_NAME) $(LIB_OPERATIONS_NAME)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB_NAME) $(LIB_OPERATIONS_NAME) -o $(NAME)
	chmod 755 $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS) $(MY_LIB_OBJECTS) $(MY_LIB_OPERATIONS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(LIB_NAME) $(LIB_OPERATIONS_NAME)

re: fclean all

.PHONY: all clean fclean re
