/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:03:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:26:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ERROR_H
# define STR_ERROR_H

# define ERR_NUM_ARGS "Invalid number of arguments."
# define ERR_NUM_PHILOSOPHERS "Number of philosophers must be >= 1."
# define ERR_TIME_TO_DIE "Time to die must be non-negative."
# define ERR_TIME_TO_EAT "Time to eat must be non-negative."
# define ERR_TIME_TO_SLEEP "Time to sleep must be non-negative."
# define ERR_MALLOC_PHILOSOPHER "Memory allocation failed."
# define ERR_FREE_PHILOSOPHER "Error freeing philosopher array."
# define ERR_INIT_MUTEX "Error initializing mutex."
# define ERR_CREATE_THREAD "Error creating thread."
# define ERR_CREATE_THREAD_PHILOSOPHER "Error creating philosopher thread."
#endif
