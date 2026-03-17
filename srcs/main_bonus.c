/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:36:16 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/21 21:55:01 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

static int	game_loop(t_game *game)
{
	static double	last_time = 0;
	double			current_time;

	current_time = get_time();
	if (last_time == 0)
		last_time = current_time;
	game->frame_time = current_time - last_time;
	last_time = current_time;
	if (!game->game_running)
		return (0);
	handle_mouse(game);
	move_player(game);
	render_frame(game);
	return (0);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	game->game_running = true;
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
}

static int	check_extension(char *filename, char *ext)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len < ext_len)
		return (0);
	return (ft_strncmp(filename + len - ext_len, ext, ext_len) == 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		error_exit("Usage: ./cub3D <map.cub>", &game);
	if (!check_extension(av[1], ".cub"))
		error_exit("Map file must have .cub extension", &game);
	if (init_game(&game) != 0)
		error_exit("Failed to initialize game", &game);
	if (parse_map(av[1], &game) != 0)
		error_exit("Failed to parse map", &game);
	if (validate_map(&game) != 0)
		error_exit("Invalid map", &game);
	if (init_player(&game) != 0)
		error_exit("Failed to initialize player", &game);
	if (init_textures(&game) != 0)
		error_exit("Failed to initialize textures", &game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
