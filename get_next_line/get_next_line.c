/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:12:39 by maricard          #+#    #+#             */
/*   Updated: 2022/12/04 08:58:25 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf(int fd, char *stash)
{
	char	*buf;
	char	*temp;
	char	bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buf);
			free(stash);
			return (0);
		}
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	int		a;
	char	*line;

	if (!*stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = malloc(sizeof(char) * (i + 1));
			if (!line)
				return (0);
			break ;
		}
		i++;
	}
	a = 0;
	while (a < i)
	{
		line[a] = stash[a];
		a++;
	}
	return (line);
}

char	*ft_remove_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		a;
	int		diff;

	i = 0;
	a = 0;
	diff = ft_strlen(stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (diff == 0)
		return (0);
	else
	{
		new_stash = malloc((diff + 1) * sizeof(char));
		if (!new_stash)
			return (0);
		while (stash[i])
			new_stash[a] = stash[i];
		new_stash[i] = '\0';
	}
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	stash = ft_buf(fd, stash);
	if (!stash)
		return (0);
	line = ft_get_line(stash);
	stash = ft_remove_line(stash);
	return (line);
}

int	main(void)
{
	int	ola;

	ola = open("teste", O_RDONLY);
	printf("'%s'", get_next_line(ola));
	printf("'%s'", get_next_line(ola));
	return (0);
}
