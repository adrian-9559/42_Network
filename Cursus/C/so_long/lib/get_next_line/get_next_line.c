/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:20:55 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 14:18:53 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

static char	*ft_extract_line(char **reminder)
{
	char	*line;
	char	*temp;
	size_t	i;

	if (!reminder || !*reminder)
		return (NULL);
	i = 0;
	while ((*reminder)[i] && (*reminder)[i] != '\n')
		i++;
	line = ft_substr(*reminder, 0, i + ((*reminder)[i] == '\n'));
	if (!line)
		return (free(*reminder), *reminder = NULL, NULL);
	temp = ft_strdup(*reminder + i + ((*reminder)[i] == '\n'));
	if (!temp)
		return (free(line), free(*reminder), *reminder = NULL, NULL);
	free(*reminder);
	*reminder = temp;
	return (line);
}

static int	ft_read_to_reminder(int fd, char **reminder)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*reminder = ft_strjoin(*reminder, buffer);
		if (!*reminder)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(*reminder, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes_read);
}

char	*ft_get_next_line(int fd)
{
	static char	*reminder;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reminder)
		reminder = ft_strdup("");
	if (!reminder)
		return (NULL);
	bytes_read = ft_read_to_reminder(fd, &reminder);
	if (bytes_read < 0 || (!bytes_read && !*reminder))
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	return (ft_extract_line(&reminder));
}
