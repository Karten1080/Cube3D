/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:56:30 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/31 02:10:09 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_pixel(t_tex *tex, int x, int y)
{
	if (!tex || !tex->pixels)
		return (0);
	if (x < 0 || x >= tex->img.width || y < 0 || y >= tex->img.height)
		return (0);
	return (tex->pixels[y * tex->img.width + x]);
}

void	error_exit(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_game(game);
	exit(1);
}

int	player_can_move(t_game *game, int px, int py)
{
	int	dirs[4][2];
	int	i;
	int	nx;
	int	ny;

	dirs[0][0] = 0;
	dirs[0][1] = -1;
	dirs[1][0] = 0;
	dirs[1][1] = 1;
	dirs[2][0] = -1;
	dirs[2][1] = 0;
	dirs[3][0] = 1;
	dirs[3][1] = 0;
	i = -1;
	while (++i < 4)
	{
		nx = px + dirs[i][0];
		ny = py + dirs[i][1];
		if (nx >= 0 && nx < game->map.width && ny >= 0
			&& ny < game->map.height && game->map.grid[ny][nx] == 0)
			return (1);
	}
	return (0);
}
