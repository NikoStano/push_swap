/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:05:14 by nistanoj          #+#    #+#             */
/*   Updated: 2025/05/20 17:40:34 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer)
{
	char	line[BUFFER_SIZE + 1];
	ssize_t	rd;

	rd = 1;
	while (!ft_strchr_gnl(buffer, '\n') && rd > 0)
	{
		rd = read(fd, line, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), NULL);
		line[rd] = '\0';
		buffer = ft_strjoin_gnl(buffer, line);
		if (!buffer)
			return (ft_strdup_gnl(""));
	}
	return (buffer);
}

static char	*find_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr_gnl(buffer, 0, i);
	return (line);
}

static char	*new_line(char *buffer)
{
	char	*nbuffer;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	nbuffer = ft_substr_gnl(buffer, i, ft_strlen_gnl(buffer) - i);
	free(buffer);
	return (nbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = find_line(buffer[fd]);
	if (!line)
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = new_line(buffer[fd]);
	return (line);
}
