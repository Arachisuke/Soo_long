/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:14:51 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 15:38:48 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	search2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != 'P' && str[i] != 'C' && str[i] != 'W') && (str[i] != '0'
				&& str[i] != 'E' && str[i] != '1'))
			return (1);
		i++;
	}
	return (0);
}
char	*strjoinfree(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (s1 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	s = malloc((sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free((char *)s1);
	return (s);
}
int	extension(char *path, t_map *map)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (open(path, __O_DIRECTORY) >= 0)
	{
		fd = open(path, __O_DIRECTORY);
		close(fd);
		error_msg(ERRDIR, map);
	}
	else
	{
		fd = open(path, O_RDONLY);
		if (read(fd, 0, 0) < 0)
			error_msg(ERRFD, map); // le fd est vide poto
		close(fd);                
			// pourquoi je le close et il est stocker ou maintenant ???
		if (ft_strncmp(path + len - 4, ".ber", 4) != 0)
			return (ERROR);
	}
	return (Success);
}

int	search(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}