/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:34:03 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/23 18:34:47 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		size;
	char	*dest;

	size = 0;
	i = 0;
	while (str[size])
		size++;
	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
	{
		return (NULL);
	}
	while (i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
