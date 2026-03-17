/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:15:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:02:44 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srrc;

	dst = (unsigned char *)dest;
	srrc = (unsigned char *)src;
	if (!dst && !srrc)
		return (NULL);
	while (n--)
	{
		*dst = *srrc;
		dst++;
		srrc++;
	}
	return (dest);
}
