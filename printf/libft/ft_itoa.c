/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:39:57 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/24 21:54:59 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_nsize(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	long int		number;
	char			*array;
	size_t			size;

	number = n;
	size = ft_itoa_nsize(n);
	if (!(array = malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (number < 0)
		number = -number;
	array[size] = '\0';
	while (size != 0)
	{
		size--;
		array[size] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		array[0] = '-';
	return (array);
}
