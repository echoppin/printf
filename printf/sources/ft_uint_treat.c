/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_treat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:39:06 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 11:05:37 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_uint(char *uint, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.dot >= 0)
		count_char += ft_width_treat(flag.dot - 1, ft_strlen(uint) - 1, 1);
	count_char += ft_putstrprec(uint, ft_strlen(uint));
	return (count_char);
}

static int	ft_put_part_uint(char *uint, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.minus == 1)
		count_char += ft_in_put_part_uint(uint, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(uint))
		flag.dot = ft_strlen(uint);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		count_char += ft_width_treat(flag.width, 0, 0);
	}
	else
		count_char += ft_width_treat(flag.width, ft_strlen(uint), flag.zero);
	if (flag.minus == 0)
		count_char += ft_in_put_part_uint(uint, flag);
	return (count_char);
}

int			ft_uint_treat(unsigned int unsi, t_flag flag)
{
	char	*uint;
	int		count_char;

	count_char = 0;
	unsi = (unsigned int)(4294967295 + 1 + unsi);
	if (flag.dot == 0 && unsi == 0)
	{
		count_char += ft_width_treat(flag.width, 0, 0);
		return (count_char);
	}
	uint = ft_uitoa(unsi);
	count_char += ft_put_part_uint(uint, flag);
	free(uint);
	return (count_char);
}
