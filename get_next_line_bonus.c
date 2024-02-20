/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:57:55 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/14 15:10:59 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*stash;
	char		*buf;
	static char	*left[4095];

	stash = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	left[fd] = read_file(fd, buf, left);
	if (left[fd] == NULL)
		return (free(buf), free(left[fd]), NULL);
	stash = ft_strduper(left[fd]);
	if (stash == NULL)
		return (free(buf), NULL);
	left[fd] = strsupp(left[fd]);
	if (left[fd] == NULL)
		return (free(buf), stash);
	return (free(buf), stash);
}

char	*read_file(int fd, char *buf, char **left)
{
	int	bytes_left;
	int	bytes_read;

	bytes_read = 1;
	bytes_left = 0;
	if (!left[fd])
	{
		left[fd] = malloc(1);
		if (left[fd] == NULL)
			return (NULL);
		left[fd][0] = '\0';
	}
	while (!ft_strchr(left[fd], '\n') && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		if (BUFFER_SIZE == 1 && bytes_read == 1)
			bytes_left++;
		left[fd] = joinfree(left[fd], buf, bytes_left);
	}
	if (ft_strlen(left[fd]) == 0)
		return (free(left[fd]), NULL);
	return (left[fd]);
}

/* int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("test2.txt", O_RDONLY);
	int fd2 = open("test3.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
} */