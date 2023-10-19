/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:12:03 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/18 11:07:11 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	get_position(char **map, t_vars *game)
{
	int	m;
	int	i;

	m = 0;
	while (m < game->map_h)
	{
		i = 0;
		while (i < game->map_w)
		{
			if (map[m][i] == 'P')
			{
				game->pos_y = m;
				game->pos_x = i;
			}
			i++;
		}
		m++;
	}
}

int	line_number(char *argv, t_vars *game)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == 0 || fd < 0)
		return (0);
	str = get_next_line(fd);
	game->map_w = (ft_strlen(str) - 1);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i = i + 1;
	}
	game->map_h = i;
	return (i);
}

int	control_map(char **map, int line, t_vars *game)
{
	int	i;
	int	m;

	i = 0;
	while (map[0][i] != '\n')
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	while (map[line][i] != '\n')
		if (map[line][i++] != '1')
			return (0);
	m = 1;
	while (m < line)
	{
		if ((map[m++][0] != '1') || (map[m][game->map_w - 1] != '1'))
			return (0);
	}
	i = 1;
	while (i <= line)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}	
	return (1);
}

int	control_map2(char **map, t_vars *game)
{
	t_vars2	utile;

	utile.c = 0;
	utile.p = 0;
	utile.e = 0;
	utile.m = 1;
	while (utile.m < game->map_h)
	{
		utile.i = 0;
		while (utile.i < game->map_w)
		{
			if (map[utile.m][utile.i] == 'C')
				utile.c++;
			if (map[utile.m][utile.i] == 'P')
				utile.p++;
			if (map[utile.m][utile.i] == 'E')
				utile.e++;
			utile.i++;
		}
		utile.m++;
	}	
	if (utile.c < 1 || utile.p < 1 || utile.e < 1)
		return (0);
	game->obj = utile.c;
	return (1);
}

char	**map_maker(char **argv, t_vars *game)
{
	char	**map;
	int		i;
	int		fd;
	int		line;

	i = 0;
	line = line_number(argv[1], game);
	map = malloc(sizeof(*map) * line);
	if (map == NULL)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (i < line)
		map[i++] = get_next_line(fd);
	if ((control_map(map, line - 1, game)) == 0)
		return (0);
	if ((control_map2(map, game)) == 0)
		return (0);
	get_position(map, game);
	return (map);
}
