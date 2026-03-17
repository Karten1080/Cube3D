/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:26:56 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/22 17:49:30 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	block_mouse_move(t_game *game)
{
	if (game->keys.mouse == false)
		game->keys.mouse = true;
	else
		game->keys.mouse = false;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_Z)
		game->keys.w = true;
	else if (keycode == KEY_S)
		game->keys.s = true;
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = true;
	else if (keycode == KEY_D)
		game->keys.d = true;
	else if (keycode == KEY_LEFT)
		game->keys.left = true;
	else if (keycode == KEY_RIGHT)
		game->keys.right = true;
	else if (keycode == KEY_M)
		block_mouse_move(game);
	else if (keycode == KEY_UP && game->player.mouse_move <= 0.05)
		game->player.mouse_move += 0.0002;
	else if (keycode == KEY_DOWN && game->player.mouse_move > 0.0003)
		game->player.mouse_move -= 0.0002;
	return (0);
}

int	handle_mouse(t_game *game)
{
	int	x;
	int	y;
	int	delta_x;

	if (game->keys.mouse == false)
		return (0);
	mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	delta_x = x - (WIDTH / 2);
	rotate_player(game, delta_x * game->player.mouse_move);
	if (x != WIDTH / 2 || y != HEIGHT / 2)
		mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
