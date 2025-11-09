/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:03:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/09 16:15:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ERROR_H
# define STR_ERROR_H

# define ERR_NUM_ARGS "\t\tInvalid number of arguments."
# define ERR_NUM_PHILOSOPHERS "\t\tNumber of philosophers must be >= 1."
# define ERR_INVALID_ARG "\t\tAll arguments must be positive integers."
# define ERR_TIME_TO_DIE "\t\tTime to die must be non-negative."
# define ERR_TIME_TO_EAT "\t\tTime to eat must be non-negative."
# define ERR_TIME_TO_SLEEP "\t\tTime to sleep must be non-negative."
# define ERR_MALLOC_PHILOSOPHER "\t\tMemory allocation failed."
# define ERR_FREE_PHILOSOPHER "\t\tError freeing philosopher array."
# define ERR_INIT_MUTEX "\t\tError initializing mutex."
# define ERR_CREATE_THREAD "\t\tError creating thread."
# define ERR_CREATE_THREAD_PHILOSOPHER "\t\tError creating philosopher thread."
/* ************************************************************************** */
/*                           FUNCTION NAMES                                   */
/* ************************************************************************** */
# define NAME_MAIN_C "\tmain"
# define NAME_FT_PHILOSOPHERS_C "\tft_philosophers"
# define NAME_FT_CONSTRUCT_DATA_C "\tft_construct_data"
# define NAME_FT_INIT_C "\tft_init_mutexes"
# define NAME_FT_CREATE_THREAD_C "\tft_create_thread"
# define NAME_FT_CREATE_PHILOSOPHER_C "\tft_create_philosophers"
# define NAME_FT_DESTROY_PHILOSOPHERS_C "\tft_destroy_philosophers"
#endif
