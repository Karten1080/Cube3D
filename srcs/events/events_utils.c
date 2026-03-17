/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:53:21 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/22 17:47:07 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_game(t_game *game)
{
	printf("\nClosing game...\n");
	game->game_running = false;
	free_game(game);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_Z)
		game->keys.w = false;
	else if (keycode == KEY_S)
		game->keys.s = false;
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = false;
	else if (keycode == KEY_D)
		game->keys.d = false;
	else if (keycode == KEY_LEFT)
		game->keys.left = false;
	else if (keycode == KEY_RIGHT)
		game->keys.right = false;
	return (0);
}
