/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 06:20:45 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/19 06:41:55 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_collision(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0
		|| map_x >= game->map.width
		|| map_y < 0
		|| map_y >= game->map.height)
		return (1);
	if (game->map.grid[map_y][map_x] == 1)
		return (1);
	return (0);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(angle)
		- game->player.dir.y * sin(angle);
	game->player.dir.y = old_dir_x * sin(angle)
		+ game->player.dir.y * cos(angle);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(angle)
		- game->player.plane.y * sin(angle);
	game->player.plane.y = old_plane_x * sin(angle)
		+ game->player.plane.y * cos(angle);
}
