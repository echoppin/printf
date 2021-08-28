/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_treat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:31:06 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 10:55:58 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_hexa(char *hx, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.dot >= 0)
		count_char += ft_width_treat(flag.dot - 1, ft_strlen(hx) - 1, 1);
	count_char += ft_putstrprec(hx, ft_strlen(hx));
	return (count_char);
}

static int	ft_put_part_hexa(char *hx, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.minus == 1)
		count_char += ft_in_put_part_hexa(hx, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(hx))
		flag.dot = ft_strlen(hx);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		count_char += ft_width_treat(flag.width, 0, 0);
	}
	else
		count_char += ft_width_treat(flag.width, ft_strlen(hx), flag.zero);
	if (flag.minus == 0)
		count_char += ft_in_put_part_hexa(hx, flag);
	return (count_char);
}

int			ft_hexa_treat(unsigned int uint, int lower, t_flag flag)
{
	char	*hx;
	int		count_char;

	count_char = 0;
	uint = (unsigned int)(4294967295 + 1 + uint);
	if (flag.dot == 0 && uint == 0)
	{
		count_char += ft_width_treat(flag.width, 0, 0);
		return (count_char);
	}
	hx = ft_ull_base((unsigned long long)uint, 16);
	if (lower == 1)
		hx = ft_str_tolower(hx);
	count_char += ft_put_part_hexa(hx, flag);
	free(hx);
	return (count_char);
}
