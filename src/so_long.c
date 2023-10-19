/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:47:05 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/18 12:10:25 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n Too many or too few arguments\n", 1);
		return (0);
	}
	game.map = map_maker(argv, &game);
	if (!game.map)
	{
		ft_putstr_fd("Error\n map invalid!\n", 1);
		return (0);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_w * SIZE,
			game.map_h * SIZE, "Welcome to Hyrule");
	start_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
