/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:23:34 by pyammoun          #+#    #+#             */
/*   Updated: 2022/02/24 16:31:45 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **buffjoin)
{
	size_t	l;
	char	*dst;
	char	*tmp;

	l = 0;
	if (!*buffjoin)
		return (NULL);
	while ((*buffjoin)[l] && (*buffjoin)[l] != '\n')
		l++;
	if ((*buffjoin)[l] == '\n')
		l++;
	if (!(*buffjoin)[l])
		tmp = NULL;
	else
		tmp = ft_strndup (*buffjoin + l, ft_strlen2(*buffjoin + l));
	dst = ft_strndup(*buffjoin, l);
	free(*buffjoin);
	*buffjoin = tmp;
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*buffjoin = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			n;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (0);
	if (buffjoin && ft_isn(buffjoin))
		return (ft_get_line(&buffjoin));
	n = read(fd, buffer, BUFFER_SIZE);
	buffer[n] = 0;
	while (n > 0 && n <= BUFFER_SIZE)
	{	
		buffjoin = ft_strjoin2(buffjoin, buffer);
		if (!buffjoin || ft_isn(buffjoin))
			break ;
		n = read (fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
	}
	return (ft_get_line(&buffjoin));
}

/*int	main(void)
{
	int	fd;

	if ((fd = open("lalista.txt", O_RDONLY)) < 3 && fd != 0) 
		return (-1);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
final
}*/
