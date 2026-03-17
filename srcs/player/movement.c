/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:26:38 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/30 14:28:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_valid_pos(t_game *game, double x, double y)
{
	double	margin;

	margin = 0.2;
	if (check_collision(game, x + margin, y + margin))
		return (0);
	if (check_collision(game, x - margin, y + margin))
		return (0);
	if (check_collision(game, x + margin, y - margin))
		return (0);
	if (check_collision(game, x - margin, y - margin))
		return (0);
	return (1);
}

static void	move_forward_backward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * speed;
	new_y = game->player.pos.y + game->player.dir.y * speed;
	if (is_valid_pos(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_pos(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

static void	move_strafe(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.plane.x * speed;
	new_y = game->player.pos.y + game->player.plane.y * speed;
	if (is_valid_pos(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_pos(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = MOVE_SPEED * game->frame_time;
	rot_speed = ROT_SPEED * game->frame_time;
	if (game->keys.w)
		move_forward_backward(game, move_speed);
	if (game->keys.s)
		move_forward_backward(game, -move_speed);
	if (game->keys.d)
		move_strafe(game, move_speed);
	if (game->keys.a)
		move_strafe(game, -move_speed);
	if (game->keys.left)
		rotate_player(game, -rot_speed);
	if (game->keys.right)
		rotate_player(game, rot_speed);
}
