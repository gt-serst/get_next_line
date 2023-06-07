/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:27:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:10:36 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
int		strchr_mod(char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, unsigned int start, int len);
char	*strjoin_mod(char *s1, char *s2);

#endif
