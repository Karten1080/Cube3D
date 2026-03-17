/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:17:48 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:04:00 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i + needle_len <= len)
	{
		if (haystack[i] == *needle
			&& !ft_strncmp(haystack + i, needle, needle_len))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
