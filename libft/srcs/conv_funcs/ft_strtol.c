/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:39:57 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:00:43 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long		result;
	int			sign;
	const char	*ptr;

	ptr = nptr;
	while (ft_isspace((unsigned char)*ptr))
		ptr++;
	sign = 1;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	result = 0;
	while (*ptr && ft_isdigit((unsigned char)*ptr))
	{
		result = result * base + (*ptr - '0');
		ptr++;
	}
	if (endptr)
		*endptr = (char *)ptr;
	return (result * sign);
}
