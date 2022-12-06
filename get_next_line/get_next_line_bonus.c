/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:57:45 by maricard          #+#    #+#             */
/*   Updated: 2022/12/06 17:39:20 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_remove_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		a;
	int		len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	len = ft_strlen(stash);
	new_stash = malloc((len - i + 1) * sizeof(char));
	if (!new_stash)
		return (0);
	i++;
	a = 0;
	while (stash[i])
		new_stash[a++] = stash[i++];
	new_stash[a] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	int		a;
	char	*line;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	a = 0;
	while (stash[a] && stash[a] != '\n')
	{
		line[a] = stash[a];
		a++;
	}
	if (stash[a] == '\n')
	{
		line[a] = stash[a];
		a++;
	}
	line [a] = '\0';
	return (line);
}

char	*ft_buf(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[bytes_read] = '\0';
		if (!stash)
		{
			stash = malloc(sizeof(char) * 1);
			stash[0] = '\0';
		}
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 | fd > 4096)
		return (0);
	stash[fd] = ft_buf(fd, stash[fd]);
	if (!stash[fd])
		return (0);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_remove_line(stash[fd]);
	return (line);
}
