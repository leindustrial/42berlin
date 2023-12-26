/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:22:37 by ole               #+#    #+#             */
/*   Updated: 2023/05/18 14:36:24 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_fill(int fd, char *storage, char *buf)
{
	ssize_t	nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (nbytes == 0)
			break ;
		buf[nbytes] = 0;
		if (!storage)
			storage = ft_strdup("");
		tmp = storage;
		storage = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (storage);
}

static char	*ft_cut(char *storage)
{
	char	*nxt_line;
	ssize_t	i;

	i = 0;
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	nxt_line = ft_substr(storage, 0, i + 1);
	if (*nxt_line == 0)
	{
		free(nxt_line);
		nxt_line = NULL;
	}
	return (nxt_line);
}

static char	*ft_rewrite(char *storage)
{
	char	*new;
	ssize_t	i;

	i = 0;
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	new = ft_substr(storage, i + 1, ft_strlen(storage) - i);
	if (*new == 0)
	{
		free(new);
		new = NULL;
	}
	free(storage);
	storage = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	char		*nxt_line;
	char		*buf;
	static char	*storage[MAX_FD];

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage[fd]);
		free(buf);
		storage[fd] = NULL;
		buf = NULL;
		return (NULL);
	}
	storage[fd] = ft_read_fill(fd, storage[fd], buf);
	free(buf);
	buf = NULL;
	if (!storage[fd])
		return (NULL);
	nxt_line = ft_cut(storage[fd]);
	storage[fd] = ft_rewrite(storage[fd]);
	return (nxt_line);
}
