/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:25:25 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/19 07:17:35 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_ray(t_game *game, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)WIDTH - 1.0;
	ray->dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1.0 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1.0 / ray->dir.y);
	ray->map_pos.x = (int)game->player.pos.x;
	ray->map_pos.y = (int)game->player.pos.y;
}

static void	calculate_step(t_game *game, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->player.pos.x - ray->map_pos.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - game->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->player.pos.y - ray->map_pos.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - game->player.pos.y)
			* ray->delta_dist.y;
	}
}

static void	cast_ray(t_game *game, int x, t_ray *ray)
{
	init_ray(game, x, ray);
	calculate_step(game, ray);
	perform_dda(game, ray);
	calculate_wall_distance(game, ray);
	calculate_wall_height(ray);
	determine_texture(ray);
	calculate_texture_x(game, ray);
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray(game, x, &ray);
		render_wall(game, x, &ray);
		x++;
	}
}
