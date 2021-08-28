/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:26:22 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/25 10:14:25 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_free(char **dest, int *words)
{
	int i;

	i = 0;
	if (words)
		free(words);
	if (dest)
	{
		while (dest[i])
			free(dest[i++]);
		free(dest);
	}
	return (NULL);
}

static int	ft_count_words(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			words++;
		while (*str != c && *str)
			str++;
	}
	return (words);
}

static int	*ft_next_word(char const *str, char c, int index)
{
	int	*char_nbr;
	int	count;
	int i;

	i = 0;
	if (!(char_nbr = (int*)malloc(sizeof(int) * index)))
		return (NULL);
	while (index--)
	{
		count = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		char_nbr[i++] = count;
	}
	return (char_nbr);
}

static char	**ft_spliter(char const *str, char c, int *words, int index)
{
	char	**dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(dest = (char**)ft_calloc(1, sizeof(char*) * (index + 1))))
		return (NULL);
	while (++i < index)
	{
		while (str[j] == c)
			j++;
		while (str[j] && str[j] != c)
		{
			if (!(dest[i] = ft_substr(str, j, words[i])))
				return (ft_split_free(dest, words));
			j += words[i];
		}
	}
	dest[i] = 0;
	return (dest);
}

char		**ft_split(char const *s, char c)
{
	char	**dest;
	int		*words;
	int		index;

	if (!s)
		return (NULL);
	index = ft_count_words(s, c);
	if (!(words = ft_next_word(s, c, index)))
		return (NULL);
	if (!(dest = ft_spliter(s, c, words, index)))
		return (NULL);
	free(words);
	return (dest);
}
