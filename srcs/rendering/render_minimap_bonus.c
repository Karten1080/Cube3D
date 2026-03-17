/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:14:45 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 16:48:10 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_rect(t_img *img, t_vec2i pos, t_vec2i size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			my_mlx_pixel_put(img, pos.x + j, pos.y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_grid(t_game *game, int start_x, int start_y)
{
	int		x;
	int		y;
	t_vec2i	pos;
	t_vec2i	size;

	y = -1;
	while (++y < MM_SIZE / MM_SCALE)
	{
		x = -1;
		while (++x < MM_SIZE / MM_SCALE)
		{
			if (start_x + x >= 0 && start_x + x < game->map.width
				&& start_y + y >= 0 && start_y + y < game->map.height)
			{
				if (game->map.grid[start_y + y][start_x + x] == 1)
				{
					pos.x = MM_OFFSET + x * MM_SCALE;
					pos.y = MM_OFFSET + y * MM_SCALE;
					size.x = MM_SCALE - 1;
					size.y = MM_SCALE - 1;
					draw_rect(&game->img, pos, size, 0xFFFFFF);
				}
			}
		}
	}
}

void	render_minimap(t_game *game)
{
	int		start_x;
	int		start_y;
	t_vec2i	pos;
	t_vec2i	size;

	pos.x = MM_OFFSET;
	pos.y = MM_OFFSET;
	size.x = MM_SIZE;
	size.y = MM_SIZE;
	draw_rect(&game->img, pos, size, 0x000000);
	start_x = (int)game->player.pos.x - (MM_SIZE / 2 / MM_SCALE);
	start_y = (int)game->player.pos.y - (MM_SIZE / 2 / MM_SCALE);
	draw_minimap_grid(game, start_x, start_y);
	pos.x = MM_OFFSET + MM_SIZE / 2 - 2;
	pos.y = MM_OFFSET + MM_SIZE / 2 - 2;
	size.x = 4;
	size.y = 4;
	draw_rect(&game->img, pos, size, 0xFF0000);
}
