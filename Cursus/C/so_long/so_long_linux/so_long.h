/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 15:02:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 100
# define BUFFER_SIZE 1024

// Map generation
# define MAX_MAP_GEN_ATTEMPTS 10000
# define MAP_ROWS 5
# define MAP_COLS 13

// Texture files
# define FLOOR_FILE_NAME "./src/textures/floor.xpm"
# define WALL_FILE_NAME "./src/textures/wall.xpm"
# define EXIT_FILE_NAME "./src/textures/exit.xpm"
# define COLLECTIBLES_FILE_NAME "./src/textures/collectible.xpm"
# define PLAYER_FILE_NAME "./src/textures/player.xpm"

// Utils map
# define HEIGHT_IMAGE 100
# define WIDTH_IMAGE 100

// Keyboard keys
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

/**
 * ENGLISH: Represents the main header file for the so_long project.
 *
 * - Contains declarations, macros, and structure definitions used
 * 	throughout the so_long program.
 * - Used to centralize and organize shared resources for the game's
 * 	implementation.
 * - Ensure all required types and function prototypes are properly
 * 	declared before use.
 *
 * SPANISH: Representa el archivo de cabecera principal para el
 * 			proyecto so_long.
 *
 * - Contiene declaraciones, macros y definiciones de estructuras
 * 	utilizadas en todo el programa so_long.
 * - Se utiliza para centralizar y organizar los recursos compartidos
 * 	para la implementación del juego.
 * - Asegúrese de que todos los tipos y prototipos de funciones
 * 	requeridos estén correctamente declarados antes de usar.
 *
 * ENGLISH/SPANISH: Variable documentation for t_game structure.
 *
 * @member {char **} map
 *      - EN: 2D array representing the game map.
 *      - ES: Matriz bidimensional que representa el mapa del juego.
 *
 * @member {void *} mlx
 *      - EN: Pointer to the MLX graphics context.
 *      - ES: Puntero al contexto gráfico MLX.
 *
 * @member {void *} wall_img
 *      - EN: Pointer to the wall image texture.
 *      - ES: Puntero a la textura de imagen de pared.
 *
 * @member {void *} floor_img
 *      - EN: Pointer to the floor image texture.
 *      - ES: Puntero a la textura de imagen de suelo.
 *
 * @member {void *} player_img
 *      - EN: Pointer to the player image texture.
 *      - ES: Puntero a la textura de imagen del jugador.
 *
 * @member {void *} exit_img
 *      - EN: Pointer to the exit image texture.
 *      - ES: Puntero a la textura de imagen de salida.
 *
 * @member {void *} collectibles_img
 *      - EN: Pointer to the collectibles image texture.
 *      - ES: Puntero a la textura de imagen de coleccionables.
 *
 * @member {void *} win
 *      - EN: Pointer to the game window.
 *      - ES: Puntero a la ventana del juego.
 *
 * @member {int} moves
 *      - EN: Number of moves made by the player.
 *      - ES: Número de movimientos realizados por el jugador.
 *
 * @member {int} rows
 *      - EN: Number of rows in the map.
 *      - ES: Número de filas en el mapa.
 *
 * @member {int} cols
 *      - EN: Number of columns in the map.
 *      - ES: Número de columnas en el mapa.
 *
 * @member {int} player_x
 *      - EN: X position of the player on the map.
 *      - ES: Posición X del jugador en el mapa.
 *
 * @member {int} player_y
 *      - EN: Y position of the player on the map.
 *      - ES: Posición Y del jugador en el mapa.
 *
 * @member {int} exit_x
 *      - EN: X position of the exit on the map.
 *      - ES: Posición X de la salida en el mapa.
 *
 * @member {int} exit_y
 *      - EN: Y position of the exit on the map.
 *      - ES: Posición Y de la salida en el mapa.
 *
 * @member {int} total_collectibles
 *      - EN: Total number of collectibles in the map.
 *      - ES: Número total de coleccionables en el mapa.
 *
 * @member {int} collectibles
 *      - EN: Number of collectibles collected by the player.
 *      - ES: Número de coleccionables recogidos por el jugador.
 */
typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*wall_img;
	void		*floor_img;
	void		*player_img;
	void		*exit_img;
	void		*collectibles_img;
	void		*win;
	int			moves;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			total_collectibles;
	int			collectibles;
}				t_game;

// Functions lib
int				ft_putstr_error(const char *str);
int				ft_putstr(const char *str);
int				ft_putchar(char c);
int				ft_putchar_error(char c);
int				ft_is_digit(unsigned char c);
int				ft_is_number(const char *str);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_count_words(const char *s, char c);
size_t			ft_strlen(const char *s);
void			ft_putnbr(int n);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_open_file_read(const char *filename);
int				ft_open_file_write(const char *filename);
// Especial functions
unsigned int	ft_simple_rand(unsigned int *seed);
// Get Next Line
char			*ft_get_next_line(int fd);

// Functions lib_project
int				ft_get_map_file(const char *filename, char ***map);
void			ft_show_map(char **map, int rows);
int				ft_small_map(char **map, int rows);
void			ft_free_map(char **map, int rows);
char			**ft_realloc_map(char **map, int new_size);
// Checker functions
int				ft_checker_name_arg(const char *str);
int				ft_checker_number_args(int argc);
int				ft_checker_file_exists(const char *filename);
int				ft_checker_map_empty_rows(char **map);
int				ft_checker_map(const char *filename);
int				ft_checker_figure(char **map, int rows);
int				ft_checker_wall(char **map, int rows, int cols);
int				ft_checker_requirements(char **map);
int				ft_checker_posible_complete(char **map, int rows);
// Generate map functions
int				ft_generate(const char *filename);
int				ft_generate_file(const char *filename);
int				ft_save_map_to_file(const char *filename, char **map, int rows);
int				ft_generate_map(const char *filename);
int				ft_generate_map_rand_internal(int *rows_cols, char **map,
					unsigned int seed, int attempt);
void			ft_generate_simple_map(int *rows_cols, char **map,
					unsigned int seed);
unsigned int	ft_better_seed(void);
void			ft_place_random_entities(int *rows_cols, char **map,
					unsigned int *seed);
// Game functions
int				ft_game(const char *filename);
int				ft_start_game(const char *filename, t_game *game);
int				ft_init_mlx(t_game *game);
int				ft_close_game(t_game *game);
int				ft_key_press(int keycode, t_game *game);
// Image
int				ft_load_textures(t_game *game);
// Player
int				ft_set_player_position(t_game *game, int x, int y);
int				ft_find_player_game(t_game *game);
int				ft_move_player(t_game *game, int new_x, int new_y);
// Collectives
int				ft_find_total_collectibles(t_game *game);
// MLX
// Image
int				ft_mlx_print_image(t_game *game, int x, int y);
int				ft_init_mlx_texture(t_game *game);

#endif
