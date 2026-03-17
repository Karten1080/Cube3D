/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:24:34 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/31 02:09:55 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	process_node(t_game *game, int *stack, int *top, int **visited)
{
	int	v[5];

	v[0] = stack[--(*top)];
	v[1] = v[0] % game->map.width;
	v[2] = v[0] / game->map.width;
	if (game->map.grid[v[2]][v[1]] == 1)
		return (1);
	if (game->map.grid[v[2]][v[1]] == -1)
		return (0);
	v[3] = -1;
	while (++v[3] < 4)
	{
		v[0] = v[1] + ((int []){1, -1, 0, 0})[v[3]];
		v[4] = v[2] + ((int []){0, 0, 1, -1})[v[3]];
		if (v[0] < 0 || v[4] < 0 || v[4] >= game->map.height
			|| v[0] >= game->map.width)
			return (0);
		if (!visited[v[4]][v[0]])
		{
			visited[v[4]][v[0]] = 1;
			stack[(*top)++] = v[4] * game->map.width + v[0];
		}
	}
	return (1);
}

static int	is_surrounded(t_game *game, int x, int y, int **visited)
{
	int	*stack;
	int	top;

	if (visited[y][x])
		return (1);
	stack = malloc(sizeof(int) * game->map.width * game->map.height);
	if (!stack)
		return (ft_putstr_fd("Error\nMalloc fail in validate\n", 2), 0);
	top = 0;
	stack[top++] = y * game->map.width + x;
	visited[y][x] = 1;
	while (top > 0)
	{
		if (!process_node(game, stack, &top, visited))
		{
			free(stack);
			return (0);
		}
	}
	free(stack);
	return (1);
}

static int	check_map_nodes(t_game *game, int **visited)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.grid[y][x] == 0
				|| (game->map.grid[y][x] != 0
					&& ft_strchr("NSEW", game->map.grid[y][x])))
			{
				if (!is_surrounded(game, x, y, visited))
					return (0);
			}
		}
		y++;
	}
	return (1);
}

static int	check_walls_closed(t_game *game)
{
	int	**visited;
	int	result;

	visited = init_visited(game);
	if (!visited)
		return (0);
	result = check_map_nodes(game, visited);
	free_visited(visited, game->map.height);
	return (result);
}

int	validate_map(t_game *game)
{
	int		px;
	int		py;
	int		count;

	printf("Validating map...\n");
	if (!game->map.grid || game->map.height == 0 || game->map.width == 0)
	{
		ft_putstr_fd("Error\nMap is empty\n", 2);
		return (1);
	}
	count = count_players(game, &px, &py);
	if (count == 0 || count > 1)
	{
		ft_putstr_fd("Error\nInvalid player count\n", 2);
		return (1);
	}
	if (!check_walls_closed(game))
	{
		ft_putstr_fd("Error\nMap is not closed\n", 2);
		return (1);
	}
	if (!player_can_move(game, px, py))
		return (ft_putstr_fd("Error\nPlayer spawn position is blocked\n", 2), 1);
	printf("Map validation successful!\n");
	return (0);
}
