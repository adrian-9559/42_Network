/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:42:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:10:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

// Library functions
void	ft_skip_whitespace(const char *cmd, int *i);
int		ft_print_str(char *str);
int		ft_print_error_str(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	ft_trim_quotes(char *arg);
void	ft_unescape_quotes(char *arg);
size_t	ft_count_words(const char *s, char c);

// File functions
int		ft_open_fd(const char *filename, int in_or_out);

// Split functions
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);

// CMD functions
int		ft_exec_cmd(char *cmd, char **envp);
char	*ft_extract_path(char **envp);
char	*ft_search_cmd_in_paths(char **paths, char *cmd);
char	*ft_get_cmd_path(char *cmd, char **envp);
int		ft_arg_len(const char *cmd, int *i);
void	ft_skip_argument(const char *cmd, int *i);
int		ft_count_args(const char *cmd);
char	*ft_get_next_arg(const char *cmd, int *i);
char	**ft_split_shell(const char *cmd);

#endif