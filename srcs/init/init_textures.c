/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:24:07 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 19:40:01 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	load_texture_pixels(t_tex *tex)
{
	int	x;
	int	y;
	int	*dst;

	tex->pixels = malloc(sizeof(int) * tex->img.width * tex->img.height);
	if (!tex->pixels)
		return (1);
	y = 0;
	while (y < tex->img.height)
	{
		x = 0;
		while (x < tex->img.width)
		{
			dst = (int *)(tex->img.addr + (y * tex->img.line_len + x
						* (tex->img.bpp / 8)));
			tex->pixels[y * tex->img.width + x] = *dst;
			x++;
		}
		y++;
	}
	return (0);
}

static int	get_texture_addr(t_tex *tex, char *path)
{
	tex->img.addr = mlx_get_data_addr(tex->img.img,
			&tex->img.bpp, &tex->img.line_len, &tex->img.endian);
	if (!tex->img.addr)
	{
		ft_putstr_fd("Error\nFailed to get texture data: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

static int	load_single_texture(t_game *game, t_tex *tex, char *path)
{
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->img.width, &tex->img.height);
	if (!tex->img.img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (get_texture_addr(tex, path) != 0)
		return (1);
	if (load_texture_pixels(tex) != 0)
	{
		ft_putstr_fd("Error\nFailed to load pixels: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

int	init_textures(t_game *game)
{
	printf("Loading textures...\n");
	if (load_single_texture(game, &game->textures[0], game->map.no_tex) != 0)
		return (1);
	printf("  ✓ North texture loaded: %s\n", game->map.no_tex);
	if (load_single_texture(game, &game->textures[1], game->map.so_tex) != 0)
		return (1);
	printf("  ✓ South texture loaded: %s\n", game->map.so_tex);
	if (load_single_texture(game, &game->textures[2], game->map.we_tex) != 0)
		return (1);
	printf("  ✓ West texture loaded: %s\n", game->map.we_tex);
	if (load_single_texture(game, &game->textures[3], game->map.ea_tex) != 0)
		return (1);
	printf("  ✓ East texture loaded: %s\n", game->map.ea_tex);
	printf("All textures loaded successfully!\n");
	return (0);
}
