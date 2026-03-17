/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:56:11 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:11 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_convert(size_t ptr)
{
	int	ret;

	ret = 0;
	if (ptr >= 16)
		ret += ft_convert(ptr >> 4);
	ret += ft_print_char("0123456789abcdef"[ptr & 0xf]);
	return (ret);
}

int	ft_print_ptr(void *ptr)
{
	int	ret;

	if (!ptr)
		return (ft_print_str("(nil)"));
	ret = 0;
	ret += ft_print_str("0x");
	ret += ft_convert((size_t)ptr);
	return (ret);
}
