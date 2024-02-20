/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:44:06 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 12:48:12 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strduper(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*strsupp(char *s)
{
	char	*newstring;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	else
		newstring = malloc(ft_strlen(s) + 1 - i);
	if (newstring == NULL)
		return (NULL);
	while (s[i])
		newstring[j++] = s[i++];
	free(s);
	newstring[j] = '\0';
	return (newstring);
}

char	*joinfree(char const *s1, char const *s2, int bytes_left)
{
	char	*s;
	int		i;
	int		j;

	if (s1 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	if (BUFFER_SIZE == 1)
		s = malloc((sizeof(char) * bytes_left + 1));
	else
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
