/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/24 11:45:01 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_bytes(int fd, char *stack)
{
	int		len;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	len = 1;
	while (!ft_strchr(stack, '\n') && len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			free(stack);
			return (NULL);
		}
		buf[len] = '\0';
		stack = ft_strjoin(stack, buf);
	}
	free(buf);
	return (stack);
}

static char	*ft_get_line(char *stack)
{
	char	*line;
	char	*substr;

	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (ft_strchr(stack, '\n'))
	{
		substr = ft_substr(stack, 0, ft_strchr(stack, '\n'));
		free(line);
		line = substr;
	}
	else
		line = ft_strjoin(line, stack);
	return (line);
}

static char	*ft_get_stack(char *stack)
{
	char	*substr;

	if (ft_strchr(stack, '\n'))
	{
		substr = ft_substr(stack, ft_strchr(stack, '\n'),
				ft_strlen(stack));
		free(stack);
		stack = substr;
	}
	else
	{
		free(stack);
		stack = NULL;
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stack[fd] = ft_get_bytes(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	if (stack[fd][0] == '\0')
		line = NULL;
	else
		line = ft_get_line(stack[fd]);
	stack[fd] = ft_get_stack(stack[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*content;
	char	*name;

	name = "text.txt";
	fd = open(name, O_RDONLY);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	close(fd);
	fd = open(name, O_RDONLY);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	return (0);
}
*/
