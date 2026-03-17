/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:25:58 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 16:45:49 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	render_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->img, x++, y, game->map.ceiling_color);
		y++;
	}
}

static void	render_floor(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->img, x++, y, game->map.floor_color);
		y++;
	}
}

void	render_floor_ceiling(t_game *game)
{
	render_ceiling(game);
	render_floor(game);
}
