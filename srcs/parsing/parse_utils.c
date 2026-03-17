/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 07:20:30 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 17:58:25 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

char	*trim_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

int	is_config_line(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A'))
	{
		if (line[2] == ' ' || line[2] == '\t')
			return (1);
	}
	if (line[0] == 'F' || line[0] == 'C')
	{
		if (line[1] == ' ' || line[1] == '\t')
			return (1);
	}
	return (0);
}

t_list	*read_map_file(char *filename)
{
	t_list	*head;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	close(fd);
	return (head);
}
