/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:34:18 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/21 22:10:22 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_map_grid(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

static void	free_textures(t_game *game)
{
	int	i;

	if (game->map.no_tex)
		free(game->map.no_tex);
	if (game->map.so_tex)
		free(game->map.so_tex);
	if (game->map.we_tex)
		free(game->map.we_tex);
	if (game->map.ea_tex)
		free(game->map.ea_tex);
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img.img)
			mlx_destroy_image(game->mlx, game->textures[i].img.img);
		if (game->textures[i].pixels)
			free(game->textures[i].pixels);
		i++;
	}
}

void	free_game(t_game *game)
{
	free_map_grid(&game->map);
	free_textures(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
