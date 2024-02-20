/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:00:55 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 12:44:48 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h"
char	*ft_strduper(const char *s);
char	*joinfree(char const *s1, char const *s2, int bytes_left);
char	*read_file(int fd, char *buf, char *left);
char	*get_next_line(int fd);
char	*strsupp(char *s);


#endif