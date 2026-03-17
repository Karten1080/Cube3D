/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:10:11 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/27 15:45:38 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_num(char *str, int *i)
{
	long	num;

	num = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (-1);
	while (ft_isdigit(str[*i]))
	{
		num = num * 10 + (str[(*i)++] - '0');
		if (num > 255)
			return (-1);
	}
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	return (num);
}

static int	check_format_rgb(char *str)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && \
		str[i] != ' ' && str[i] != '\t')
			return (0);
		if (str[i] == ',')
			sep++;
		i++;
	}
	if (sep != 2)
		return (0);
	return (1);
}

static int	parse_rgb(char *str, int *color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (*color != -1)
		return (1);
	str = skip_whitespace(str);
	if (!check_format_rgb(str))
		return (1);
	i = 0;
	r = parse_num(str, &i);
	if (r == -1 || str[i++] != ',')
		return (1);
	g = parse_num(str, &i);
	if (g == -1 || str[i++] != ',')
		return (1);
	b = parse_num(str, &i);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (b == -1 || (str[i] && str[i] != '\n'))
		return (1);
	*color = (r << 16) | (g << 8) | b;
	return (0);
}

static int	parse_texture(char *line, char **tex)
{
	char	*path;

	if (*tex != NULL)
		return (1);
	path = skip_whitespace(line + 2);
	if (!*path)
		return (1);
	trim_newline(path);
	*tex = ft_strdup(path);
	return (*tex == NULL);
}

int	parse_line(char *line, t_game *game)
{
	char	*trimmed;

	trimmed = skip_whitespace(line);
	if (!*trimmed || *trimmed == '\n')
		return (0);
	if (trimmed[0] == 'N' && trimmed[1] == 'O'
		&& (trimmed[2] == ' ' || trimmed[2] == '\t'))
		return (parse_texture(trimmed, &game->map.no_tex));
	if (trimmed[0] == 'S' && trimmed[1] == 'O'
		&& (trimmed[2] == ' ' || trimmed[2] == '\t'))
		return (parse_texture(trimmed, &game->map.so_tex));
	if (trimmed[0] == 'W' && trimmed[1] == 'E'
		&& (trimmed[2] == ' ' || trimmed[2] == '\t'))
		return (parse_texture(trimmed, &game->map.we_tex));
	if (trimmed[0] == 'E' && trimmed[1] == 'A'
		&& (trimmed[2] == ' ' || trimmed[2] == '\t'))
		return (parse_texture(trimmed, &game->map.ea_tex));
	if (trimmed[0] == 'F' && (trimmed[1] == ' ' || trimmed[1] == '\t'))
		return (parse_rgb(trimmed + 2, &game->map.floor_color));
	if (trimmed[0] == 'C' && (trimmed[1] == ' ' || trimmed[1] == '\t'))
		return (parse_rgb(trimmed + 2, &game->map.ceiling_color));
	return (0);
}
