/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:49:51 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:00:37 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_atol(const char *nptr)
{
	int			neg;
	long long	nb;

	neg = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		nb = nb * 10 + *nptr - '0';
		if (nb * neg > INT_MAX)
			return ((long)INT_MAX + 1);
		if (nb * neg < INT_MIN)
			return ((long)INT_MIN - 1);
		nptr++;
	}
	return (nb * neg);
}
