/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:48:35 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/18 12:10:43 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	miw(t_vars *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	map_read2(t_vars *game)
{
	game->y = 0;
	while (game->y < game->map_h)
	{
		game->x = 0;
		while (game->x < game->map_w)
		{	
			miw(game, game->x * SIZE, game->y * SIZE, game->ground);
			if (game->map[game->y][game->x] == 'C')
				miw(game, game->x * SIZE, game->y * SIZE, game->ruby);
			if (game->map[game->y][game->x] == '1')
				miw(game, game->x * SIZE, game->y * SIZE, game->bush);
			if (game->map[game->y][game->x] == 'E')
				miw(game, game->x * SIZE, game->y * SIZE, game->exit_current);
			if (game->y == game->pos_y && game->x == game->pos_x)
				miw(game, game->x * SIZE, game->y * SIZE, game->link_current);
			if (game->map[game->y][game->x] == 'V')
				miw(game, game->x * SIZE, game->y * SIZE, game->villain);
			game->x = game->x + 1;
		}
		game->y = game->y + 1;
	}
	game->string = ft_itoa(game->movement);
	mlx_string_put(game->mlx, game->win,
		game->pos_x * SIZE, game->pos_y * SIZE, 612296, game->string);
	free (game->string);
}

void	map_read(t_vars *game)
{
	game->y = 0;
	while (game->y < game->map_h)
	{
		game->x = 0;
		while (game->x < game->map_w)
		{	
			miw(game, game->x * SIZE, game->y * SIZE, game->ground);
			if (game->map[game->y][game->x] == 'C')
				miw(game, game->x * SIZE, game->y * SIZE, game->ruby);
			if (game->map[game->y][game->x] == 'P')
			{
				miw(game, game->x * SIZE, game->y * SIZE, game->link_current);
				game->pos_y = game->y;
				game->pos_x = game->x;
			}
			if (game->map[game->y][game->x] == '1')
				miw(game, game->x * SIZE, game->y * SIZE, game->bush);
			if (game->map[game->y][game->x] == 'E')
				miw(game, game->x * SIZE, game->y * SIZE, game->exit);
			if (game->map[game->y][game->x] == 'V')
				miw(game, game->x * SIZE, game->y * SIZE, game->villain);
			game->x += 1;
		}
		game->y += 1;
	}	
}

void	map_load(t_vars *game)
{
	game->link_front = mlx_xpm_file_to_image(game->mlx,
			"./sprites/link_front.xpm", &game->width, &game->height);
	game->link_back = mlx_xpm_file_to_image(game->mlx,
			"./sprites/link_back.xpm", &game->width, &game->height);
	game->link_left = mlx_xpm_file_to_image(game->mlx,
			"./sprites/link_left.xpm", &game->width, &game->height);
	game->link_right = mlx_xpm_file_to_image(game->mlx,
			"./sprites/link_right.xpm", &game->width, &game->height);
	game->ruby = mlx_xpm_file_to_image(game->mlx,
			"./sprites/ruby.xpm", &game->width, &game->height);
	game->bush = mlx_xpm_file_to_image(game->mlx,
			"./sprites/bush.xpm", &game->width, &game->height);
	game->ground = mlx_xpm_file_to_image(game->mlx,
			"./sprites/ground.xpm", &game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_close.xpm", &game->width, &game->height);
	game->exit_finish = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_open.xpm", &game->width, &game->height);
	game->villain = mlx_xpm_file_to_image(game->mlx,
			"./sprites/villain.xpm", &game->width, &game->height);
}

void	start_game(t_vars *game)
{
	map_load(game);
	game->link_current = game->link_front;
	game->exit_current = game->exit;
	game->movement = 0;
	map_read(game);
	mlx_hook(game->win, 2, 1L << 0, position_hero, game);
	mlx_hook(game->win, 17, 0, closewindow, game);
}
