/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:53:39 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/23 23:18:50 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_keys(t_keys *keys)
{
	keys->w = false;
	keys->a = false;
	keys->s = false;
	keys->d = false;
	keys->left = false;
	keys->right = false;
	keys->up = false;
	keys->down = false;
	keys->mouse = true;
}

static void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->no_tex = NULL;
	map->so_tex = NULL;
	map->we_tex = NULL;
	map->ea_tex = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
}

void	init_player_struct(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = MOVE_SPEED;
	player->mouse_move = MOUSE_SENS;
	player->rot_speed = ROT_SPEED;
}

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (1);
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		return (1);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
	if (!game->img.addr)
		return (1);
	game->img.width = WIDTH;
	game->img.height = HEIGHT;
	return (0);
}

int	init_game(t_game *game)
{
	int	i;

	memset(game, 0, sizeof(t_game));
	init_keys(&game->keys);
	init_map(&game->map);
	init_player_struct(&game->player);
	if (init_mlx(game) != 0)
		return (1);
	game->game_running = false;
	game->frame_time = 0;
	i = 0;
	while (i < 4)
	{
		game->textures[i].img.img = NULL;
		game->textures[i].pixels = NULL;
		i++;
	}
	return (0);
}
