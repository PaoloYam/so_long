/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:13:26 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/18 13:45:30 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endit(t_vars *game)
{
	int	i;

	i = 0;
	mlx_clear_window(game->mlx, game->win);
	while (i < game->map_h)
	{
		free (game->map[i]);
		i++;
	}
	free (game->map);
	exit(EXIT_SUCCESS);
}

int	closewindow(t_vars *game)
{
	endit(game);
	return (0);
}

int	position_hero(int keycode, t_vars *game)
{
	if (keycode == 13)
	{
		game->link_current = game->link_back;
		movement_hero(keycode, game);
	}				
	if (keycode == 0)
	{
		game->link_current = game->link_left;
		movement_hero(keycode, game);
	}
	if (keycode == 1)
	{
		game->link_current = game->link_front;
		movement_hero(keycode, game);
	}
	if (keycode == 2)
	{
		game->link_current = game->link_right;
		movement_hero(keycode, game);
	}
	if (keycode == 53)
		endit(game);
	return (0);
}

int	movement_hero(int keycode, t_vars *game)
{
	if (keycode == 13 && check_movement(-1, 0, game))
		game->pos_y -= 1;
	if (keycode == 0 && check_movement(0, -1, game))
		game->pos_x -= 1;
	if (keycode == 1 && check_movement(1, 0, game))
		game->pos_y += 1;
	if (keycode == 2 && check_movement(0, 1, game))
		game->pos_x += 1;
	map_read2(game);
	return (0);
}

int	check_movement(int y, int x, t_vars *game)
{
	if (game->map[game->pos_y + y][game->pos_x + x] == '1')
	{
		return (0);
	}	
	if (game->map[game->pos_y + y][game->pos_x + x] == 'V')
		endit(game);
	if (game->map[game->pos_y + y][game->pos_x + x] == 'C')
	{
		game->obj -= 1;
		game->map[game->pos_y + y][game->pos_x + x] = '0';
	}
	if (game->obj == 0)
		game->exit_current = game->exit_finish;
	if (game->obj == 0 && game->map[game->pos_y + y][game->pos_x + x] == 'E')
		endit(game);
	game->movement += 1;
	return (1);
}
