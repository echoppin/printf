/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:40:02 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/17 12:20:11 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_estim(long n)
{
	size_t	estim;
	int		is_negative;

	estim = 0;
	is_negative = 0;
	if (n < 0)
	{
		estim++;
		is_negative++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, long nbr, int size, int is_negative)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (size + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	is_negative = 0;
	if (nbr < 0)
	{
		is_negative++;
		nbr = -nbr;
	}
	rtn[size] = '\0';
	while (--size)
	{
		rtn[size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (is_negative == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char		*ft_uitoa(unsigned int n)
{
	int		size;
	char	*rtn;
	long	nbr;
	int		is_negative;

	rtn = 0;
	nbr = n;
	is_negative = 0;
	size = ft_estim(nbr);
	if (!(rtn = ft_gen(rtn, nbr, size, is_negative)))
		return (0);
	return (rtn);
}
