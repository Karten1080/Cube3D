/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:27:16 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:08 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_nbr(int n)
{
	int	nb;

	nb = 0;
	if (n == INT_MIN)
	{
		nb += ft_print_str("-2147483648");
		return (nb);
	}
	if (n < 0)
	{
		nb += ft_print_char('-');
		n = -n;
	}
	if (n / 10)
	{
		nb += ft_print_nbr(n / 10);
		nb += ft_print_char((n % 10) + 48);
	}
	else
		nb += ft_print_char(n + 48);
	return (nb);
}

int	ft_print_nbru(unsigned int n)
{
	int	nb;

	nb = 0;
	if (n / 10)
	{
		nb += ft_print_nbr(n / 10);
		nb += ft_print_char((n % 10) + 48);
	}
	else
		nb += ft_print_char(n + 48);
	return (nb);
}
