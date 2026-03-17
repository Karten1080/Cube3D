/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:10:23 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/23 23:01:18 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_map_dimensions(t_list *map_lines, t_game *game)
{
	int		width;
	int		height;
	char	*line;
	int		len;

	width = 0;
	height = 0;
	while (map_lines)
	{
		line = (char *)map_lines->value;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		height++;
		map_lines = map_lines->next;
	}
	game->map.width = width;
	game->map.height = height;
	return (0);
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (visited[i])
			free(visited[i]);
		i++;
	}
	free(visited);
}

int	**init_visited(t_game *game)
{
	int	**visited;
	int	y;
	int	x;

	visited = malloc(sizeof(int *) * game->map.height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < game->map.height)
	{
		visited[y] = malloc(sizeof(int) * game->map.width);
		if (!visited[y])
		{
			free_visited(visited, y);
			return (NULL);
		}
		x = -1;
		while (++x < game->map.width)
			visited[y][x] = 0;
		y++;
	}
	return (visited);
}

int	count_players(t_game *game, int *px, int *py)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.grid[y][x] != 0
				&& ft_strchr("NSEW", game->map.grid[y][x]))
			{
				count++;
				*px = x;
				*py = y;
			}
		}
		y++;
	}
	return (count);
}

int	check_missing_config(t_game *game)
{
	if (!game->map.no_tex || !game->map.so_tex || !game->map.we_tex
		|| !game->map.ea_tex || game->map.floor_color == -1
		|| game->map.ceiling_color == -1)
	{
		ft_putstr_fd("Error\nMissing config\n", 2);
		return (1);
	}
	return (0);
}
