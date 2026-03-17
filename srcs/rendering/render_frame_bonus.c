/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:26:12 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/17 00:04:13 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_frame(t_game *game)
{
	render_floor_ceiling(game);
	raycasting(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
