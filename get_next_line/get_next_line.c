/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:03:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:27 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

char	*ft_strdup(char *str)
{
	char	*new;
	int	len = 0x0;
	int	i = -1;
	while (str[len])
		len++;
	new = malloc (sizeof(char) * len + 1);
	while (++i < len)
		new[i] = str[i];
	str[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	int		bytes;
	char	buff;
	int		i = 0x0;
	char	heap[5000];

	if (fd < 0x0 || BUFFER_SIZE <= 0x0)
		return(0x0);
	while ((bytes = read(fd, &buff, 1)) && bytes > 0)
	{
		heap[i++] = buff;
		if (buff == '\n' || !buff)
			break;
	}
	heap[i] = '\0';
	if (i == 0 && bytes >= 0)
		return (0x0);
	return (ft_strdup(heap));
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
