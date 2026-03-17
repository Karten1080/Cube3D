/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:16:31 by nistanoj          #+#    #+#             */
/*   Updated: 2025/11/17 07:03:34 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_cntwrds(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_substr_tochar(const char *s, char c, size_t *j)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	while (s[*j] == c && s[*j])
		(*j)++;
	start = *j;
	while (s[*j] != c && s[*j])
		(*j)++;
	end = *j;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s[start + i];
		i++;
	}
	str[end - start] = '\0';
	return (str);
}

static void	ft_free(char **split, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(split[j++]);
	free (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	words = ft_cntwrds(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		split[i] = ft_substr_tochar(s, c, &j);
		if (!split[i])
		{
			ft_free(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
