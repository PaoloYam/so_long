/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:10:57 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/18 11:41:46 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define SIZE 200

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	void	*link_front;
	void	*link_back;
	void	*link_left;
	void	*link_right;
	void	*link_current;
	void	*ruby;
	void	*bush;
	void	*ground;
	void	*exit;
	void	*exit_finish;
	void	*exit_current;
	void	*villain;
	int		movement;
	int		pos_y;
	int		pos_x;
	int		map_w;
	int		map_h;
	int		obj;
	int		width;
	int		height;
	int		x;
	int		y;
	char	*string;
}				t_vars;

typedef struct u_vars {
	int	c;
	int	p;
	int	e;
	int	m;
	int	i;
}	t_vars2;

void	map_read(t_vars *game);
void	map_read2(t_vars *game);
void	map_load(t_vars *game);
int		line_number(char *argv, t_vars *game);
int		control_map(char **map, int line, t_vars *game);
char	**map_maker(char **argv, t_vars *game);
void	start_game(t_vars *game);
void	miw(t_vars *game, int i, int j, void *img);
int		position_hero(int keycode, t_vars *game);
int		movement_hero(int keycode, t_vars *game);
int		check_movement(int y, int x, t_vars *game);
void	miw(t_vars *game, int i, int j, void *img);
void	endit(t_vars *game);
int		closewindow(t_vars *game);
#endif 
