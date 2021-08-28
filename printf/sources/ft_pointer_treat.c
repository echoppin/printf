/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:34:07 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 10:59:56 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_pointer(char *pt, t_flag flag)
{
	int	count_char;

	count_char = 0;
	count_char += ft_putstrprec("0x", 2);
	if (flag.dot >= 0)
	{
		count_char += ft_width_treat(flag.dot, ft_strlen(pt), 1);
		count_char += ft_putstrprec(pt, flag.dot);
	}
	else
		count_char += ft_putstrprec(pt, ft_strlen(pt));
	return (count_char);
}

int			ft_pointer_treat(unsigned long long ull, t_flag flag)
{
	char	*pt;
	int		count_char;

	count_char = 0;
	if (ull == 0 && flag.dot == 0)
	{
		count_char += ft_width_treat(flag.width, 2, 0);
		return (count_char += ft_putstrprec("0x", 2));
	}
	pt = ft_ull_base(ull, 16);
	pt = ft_str_tolower(pt);
	if ((size_t)flag.dot < ft_strlen(pt))
		flag.dot = ft_strlen(pt);
	if (flag.minus == 1)
		count_char += ft_in_put_part_pointer(pt, flag);
	count_char += ft_width_treat(flag.width, ft_strlen(pt) + 2, 0);
	if (flag.minus == 0)
		count_char += ft_in_put_part_pointer(pt, flag);
	free(pt);
	return (count_char);
}
