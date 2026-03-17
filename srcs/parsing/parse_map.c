/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:55:52 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/22 18:02:52 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	process_char(t_game *game, char c, int x, int y)
{
	if (c == '1')
		game->map.grid[y][x] = 1;
	else if (c == '0')
		game->map.grid[y][x] = 0;
	else if (ft_strchr("NSEW", c))
		game->map.grid[y][x] = c;
	else if (c == 32 || c == 9)
		game->map.grid[y][x] = -1;
	else
	{
		ft_putstr_fd("Error\nInvalid map char: '", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		return (1);
	}
	return (0);
}

static int	fill_line(t_game *game, char *line, int y)
{
	int	x;
	int	len;

	game->map.grid[y] = malloc(sizeof(int) * game->map.width);
	if (!game->map.grid[y])
		return (1);
	x = 0;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	while (x < len)
	{
		if (process_char(game, line[x], x, y))
			return (1);
		x++;
	}
	while (x < game->map.width)
		game->map.grid[y][x++] = -1;
	return (0);
}

static int	process_map(t_list *node, t_game *game)
{
	int	y;

	get_map_dimensions(node, game);
	if (game->map.height == 0)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		return (1);
	}
	game->map.grid = ft_calloc(game->map.height, sizeof(int *));
	if (!game->map.grid)
		return (1);
	y = 0;
	while (node)
	{
		if (fill_line(game, (char *)node->value, y))
			return (1);
		node = node->next;
		y++;
	}
	return (0);
}

static int	parse_configs(t_list **curr, t_game *game)
{
	char	*l;

	while (*curr)
	{
		l = (char *)(*curr)->value;
		if (is_config_line(skip_whitespace(l)))
		{
			if (parse_line(l, game))
				return (1);
		}
		else if (is_map_char(*skip_whitespace(l)))
			break ;
		else if (*skip_whitespace(l) != '\0' && *skip_whitespace(l) != '\n')
		{
			ft_putstr_fd("Error\nInvalid config line\n", 2);
			return (1);
		}
		*curr = (*curr)->next;
	}
	return (0);
}

int	parse_map(char *filename, t_game *game)
{
	t_list	*head;
	t_list	*curr;

	head = read_map_file(filename);
	if (!head)
	{
		ft_putstr_fd("Error\nCannot open file: \n", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	curr = head;
	if (parse_configs(&curr, game))
		return (ft_lstclear(&head, free), 1);
	if (check_missing_config(game))
		return (ft_lstclear(&head, free), 1);
	if (process_map(curr, game))
		return (ft_lstclear(&head, free), 1);
	ft_lstclear(&head, free);
	printf("Map loaded: %dx%d\n", game->map.width, game->map.height);
	return (0);
}
