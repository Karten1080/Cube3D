/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:25:39 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/30 14:34:52 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	apply_shading(int color, double distance, int side)
{
	int		r;
	int		g;
	int		b;
	double	factor;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	factor = 1.0 / (1.0 + distance * 0.1);
	if (factor > 1.0)
		factor = 1.0;
	if (factor < 0.3)
		factor = 0.3;
	if (side == 1)
		factor *= 0.7;
	r = (int)(r * factor);
	g = (int)(g * factor);
	b = (int)(b * factor);
	return ((r << 16) | (g << 8) | b);
}

void	render_wall(t_game *game, int x, t_ray *ray)
{
	int		y;
	t_tex	*text;

	if (ray->tex_num < 0 || ray->tex_num >= 4)
		return ;
	text = &game->textures[ray->tex_num];
	text->step = 1.0 * TEX_SIZE / ray->line_height;
	text->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* text->step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		text->tex_y = (int)text->tex_pos & (TEX_SIZE - 1);
		text->tex_pos += text->step;
		if (text->pixels && ray->tex_x >= 0 && ray->tex_x < TEX_SIZE
			&& text->tex_y >= 0 && text->tex_y < TEX_SIZE)
		{
			text->color = text->pixels[TEX_SIZE * text->tex_y + ray->tex_x];
			text->color = apply_shading(text->color, ray->perp_wall_dist,
					ray->side);
			my_mlx_pixel_put(&game->img, x, y, text->color);
		}
		y++;
	}
}
