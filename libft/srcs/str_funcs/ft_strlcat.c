/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:17:16 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:47 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dest);
	i = 0;
	if (dstlen >= size)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	return (dstlen + srclen);
}
