#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rcs $(NOM) $(OBJ) > /dev/null 2>&1
	@ranlib $(NOM) > /dev/null 2>&1
	@if [ $$? -ne 0 ]; then \
		echo "\033[31mError durante la compilación.\033[0m"; \
	fi

%.o: %.c
	@cc $(CFLAGS) -c -o $@ $<

%.o: %.m
	@cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
