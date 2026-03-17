/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:25:39 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 16:45:49 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_texture_mapping(t_ray *ray, t_tex *text)
{
	text->step = 1.0 * TEX_SIZE / ray->line_height;
	text->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* text->step;
}

static void	draw_texture_column(t_game *game, int x, t_ray *ray, t_tex *text)
{
	int	y;
	int	tex_y;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)text->tex_pos & (TEX_SIZE - 1);
		text->tex_pos += text->step;
		if (text->pixels)
		{
			text->color = text->pixels[TEX_SIZE * tex_y + ray->tex_x];
			my_mlx_pixel_put(&game->img, x, y, text->color);
		}
		y++;
	}
}

void	render_wall(t_game *game, int x, t_ray *ray)
{
	t_tex	*text;

	if (ray->tex_num < 0 || ray->tex_num >= 4)
		return ;
	text = &game->textures[ray->tex_num];
	init_texture_mapping(ray, text);
	draw_texture_column(game, x, ray, text);
}
