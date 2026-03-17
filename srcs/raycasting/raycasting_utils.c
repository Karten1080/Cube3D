/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 07:12:20 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/19 07:15:47 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map_pos.x >= 0 && ray->map_pos.x < game->map.width
			&& ray->map_pos.y >= 0
			&& ray->map_pos.y < game->map.height
			&& game->map.grid[ray->map_pos.y][ray->map_pos.x] == 1)
			hit = 1;
	}
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_pos.x - game->player.pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_pos.y - game->player.pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
}

void	calculate_wall_height(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	determine_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			ray->tex_num = 3;
		else
			ray->tex_num = 2;
	}
	else
	{
		if (ray->step.y > 0)
			ray->tex_num = 1;
		else
			ray->tex_num = 0;
	}
}

void	calculate_texture_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)TEX_SIZE);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
}
