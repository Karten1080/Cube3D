/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:24:58 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/21 22:00:45 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_camera(t_player *p, double x, double y)
{
	p->dir.x = x;
	p->dir.y = y;
	p->plane.x = -y * 0.66;
	p->plane.y = x * 0.66;
}

static void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
		set_camera(player, 0, -1);
	else if (dir == 'S')
		set_camera(player, 0, 1);
	else if (dir == 'W')
		set_camera(player, -1, 0);
	else if (dir == 'E')
		set_camera(player, 1, 0);
}

static int	find_player_position(t_game *game, char *dir)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] != 0
				&& ft_strchr("NSEW", game->map.grid[y][x]))
			{
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
				*dir = game->map.grid[y][x];
				game->map.grid[y][x] = 0;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	init_player(t_game *game)
{
	char	dir;

	printf("Initializing player...\n");
	if (find_player_position(game, &dir))
	{
		ft_putstr_fd("Error\nNo player starting position found\n", 2);
		return (1);
	}
	set_player_direction(&game->player, dir);
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	printf("Player initialized at (%.2f, %.2f) facing %c\n",
		game->player.pos.x, game->player.pos.y, dir);
	return (0);
}
