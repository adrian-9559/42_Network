/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:03:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:00:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ERROR_H
# define STR_ERROR_H

# define ERR_NUM_ARGS "\tInvalid number of arguments."
# define ERR_NUM_PHILOSOPHERS "\tNumber of philosophers must be >= 1."
# define ERR_TIME_TO_DIE "\tTime to die must be non-negative."
# define ERR_TIME_TO_EAT "\tTime to eat must be non-negative."
# define ERR_TIME_TO_SLEEP "\tTime to sleep must be non-negative."
# define ERR_MALLOC_PHILOSOPHER "\tMemory allocation failed."
# define ERR_FREE_PHILOSOPHER "\tError freeing philosopher array."
# define ERR_INIT_MUTEX "\tError initializing mutex."
# define ERR_CREATE_THREAD "\tError creating thread."
# define ERR_CREATE_THREAD_PHILOSOPHER "\tError creating philosopher thread."
/* ************************************************************************** */
/*                           FUNCTION NAMES                                   */
/* ************************************************************************** */
# define NAME_MAIN_C "main"
# define NAME_FT_PHILOSOPHERS_C "ft_philosophers"
# define NAME_FT_CONSTRUCT_DATA_C "ft_construct_data"
# define NAME_FT_INIT_C "ft_init_mutexes"
# define NAME_FT_CREATE_THREAD_C "ft_create_thread"
# define NAME_FT_CREATE_PHILOSOPHER_C "ft_create_philosophers"
# define NAME_FT_DESTROY_PHILOSOPHERS_C "ft_destroy_philosophers"
#endif
