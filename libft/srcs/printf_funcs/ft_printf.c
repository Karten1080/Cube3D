/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:29:01 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:16 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_find_format(const char c, va_list args)
{
	if (c == '%')
		return (ft_print_char('%'));
	else if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_nbru(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else
		return (-1);
}

static int	ft_format_check(const char *format, va_list args)
{
	int	i;
	int	ret;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			ret = ft_find_format(format[++i], args);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = ft_format_check(format, args);
	va_end(args);
	return (ret);
}
