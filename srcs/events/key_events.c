/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:26:56 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/30 22:00:20 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	apply_dir(bool *key, bool *old_key)
// {
// 	if (*old_key == true)
// 		*old_key = false;
// 	*key = true;
// }

// int	key_press(int keycode, t_game *game)
// {
// 	if (keycode == KEY_ESC)
// 		close_game(game);
// 	else if (keycode == KEY_W || keycode == KEY_Z)
// 		apply_dir(&game->keys.w, &game->keys.s);
// 	else if (keycode == KEY_S)
// 		apply_dir(&game->keys.s, &game->keys.w);
// 	else if (keycode == KEY_A || keycode == KEY_Q)
// 		apply_dir(&game->keys.a, &game->keys.d);
// 	else if (keycode == KEY_D)
// 		apply_dir(&game->keys.d, &game->keys.a);
// 	else if (keycode == KEY_LEFT)
// 		apply_dir(&game->keys.left, &game->keys.right);
// 	else if (keycode == KEY_RIGHT)
// 		apply_dir(&game->keys.right, &game->keys.left);
// 	return (0);
// }

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
	return (0);
}
