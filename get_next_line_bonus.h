/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:58:20 by wzeraig           #+#    #+#             */
/*   Updated: 2024/01/05 12:46:27 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strduper(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int bytes_left);
char	*read_file(int fd, char *buf, char **left);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*strsupp(char *s);
char	*ft_strchr(const char *s, int c);

#endif