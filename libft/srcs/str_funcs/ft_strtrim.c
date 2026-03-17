/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:18:01 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:04:06 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static unsigned int	inset(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	beg;
	size_t	end;
	size_t	i;

	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] && inset(set, s1[beg]))
		beg++;
	while ((end > beg) && inset(set, s1[end - 1]))
		end--;
	str = malloc(end - beg + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
