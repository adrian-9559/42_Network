/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 23:46:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAP_ROWS
#  define MAP_ROWS 5
# endif

# ifndef MAP_COLS
#  define MAP_COLS 13
# endif

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
// Checker functions
int				ft_checker_name_arg(const char *str);
int				ft_checker_number_args(int argc);
int				ft_checker_file_exists(const char *filename);
int				ft_checker_map_empty_rows(char **map);
int				ft_checker_map(const char *filename);
void			ft_free_map(char **map, int rows);
char			**ft_realloc_map(char **map, int new_size);
int				ft_checker_figure(char **map, int rows);
int				ft_checker_wall(char **map, int rows, int cols);
int				ft_checker_requirements(char **map);
// Generate map functions
int				ft_generate(const char *filename);
int				ft_generate_file(const char *filename);
int				ft_save_map_to_file(const char *filename, char **map, int rows);
int				ft_generate_map(const char *filename);
int				ft_generate_map_rand(int *rows_cols, char **map,
					unsigned int seed);
void			ft_generate_simple_map(int *rows_cols, char **map,
					unsigned int seed);
unsigned int	ft_better_seed(void);
void			ft_place_random_entities(int *rows_cols, char **map,
					unsigned int *seed);

#endif