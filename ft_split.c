/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muakbas <muakbas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:37:40 by muakbas           #+#    #+#             */
/*   Updated: 2025/07/05 13:50:48 by muakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_parts(const char	*s, char c)
{
	size_t	count;
	int		in_part;

	count = 0;
	in_part = 0;
	while (*s)
	{
		if (*s != c && in_part == 0)
		{
			in_part = 1;
			count++;
		}
		else if (*s == c)
			in_part = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	split_parts(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
				return (j);
			j++;
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		ret_val;

	if (!s)
		return (NULL);
	splitted = malloc((count_parts(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	ret_val = split_parts(splitted, s, c);
	if (ret_val >= 0)
	{
		free_split(splitted, ret_val);
		return (NULL);
	}
	return (splitted);
}
