/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:41:50 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/14 16:55:17 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*left;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	left = read_file(fd, buf, left);
	if (left == NULL)
		return (free(buf), free(left), NULL);
	line = ft_strduper(left);
	if (line == NULL)
		return (free(buf), NULL);
	left = strsupp(left);
	if (left == NULL)
		return (free(buf), line);
	return (free(buf), line);
}

char	*read_file(int fd, char *buf, char *left)
{
	int	bytes_left;
	int	bytes_read;

	bytes_read = 1;
	bytes_left = 0;
	if (!left)
	{
		left = malloc(1);
		if (left == NULL)
			return (NULL);
		left[0] = '\0';
	}
	while (!ft_strchr(left, '\n') && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		if (BUFFER_SIZE == 1 && bytes_read == 1)
			bytes_left++;
		left = joinfree(left, buf, bytes_left);
	}
	if (ft_strlen(left) == 0)
		return (free(left), NULL);
	return (left);
}

/* int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
} */