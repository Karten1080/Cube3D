/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:18:10 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:13 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_str(char *s)
{
	int	ret;
	int	i;

	if (!s)
		return (ft_print_str("(null)"));
	ret = 0;
	i = 0;
	while (s[i])
	{
		ret += ft_print_char(s[i]);
		i++;
	}
	return (ret);
}
