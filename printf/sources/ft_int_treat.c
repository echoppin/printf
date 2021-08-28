/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_treat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:32:13 by echoppin          #+#    #+#             */
/*   Updated: 2021/01/11 17:11:12 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part(char *dest_i, int save_i, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (save_i < 0 && flag.dot >= 0 && save_i != -2147483648)
		ft_putchar('-');
	if (flag.dot >= 0)
		count_char += ft_width_treat(flag.dot - 1, ft_strlen(dest_i) - 1, 1);
	count_char += ft_putstrprec(dest_i, ft_strlen(dest_i));
	return (count_char);
}

static int	ft_put_part_int(char *dest_i, int save_i, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.minus == 1)
		count_char += ft_in_put_part(dest_i, save_i, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(dest_i))
		flag.dot = ft_strlen(dest_i);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		count_char += ft_width_treat(flag.width, 0, 0);
	}
	else
		count_char += ft_width_treat(flag.width, ft_strlen(dest_i), flag.zero);
	if (flag.minus == 0)
		count_char += ft_in_put_part(dest_i, save_i, flag);
	return (count_char);
}

int			ft_int_treat(int i, t_flag flag)
{
	char	*dest_i;
	int		count_char;
	int		save_i;

	count_char = 0;
	save_i = i;
	if (flag.dot == 0 && i == 0)
		return (count_char += ft_width_treat(flag.width, 0, 0));
	if (flag.width > 0 && flag.zero == 1 && flag.minus == 1)
		flag.zero = 0;
	if (i < 0 && (flag.dot >= 0 || flag.zero == 1))
	{
		if (flag.zero == 1 && flag.dot < 0 && save_i != -2147483648)
			ft_putstrprec("-", 1);
		i *= -1;
		flag.zero = 1;
		flag.width--;
		if (save_i != -2147483648)
			count_char++;
	}
	dest_i = ft_itoa(i);
	count_char += ft_put_part_int(dest_i, save_i, flag);
	free(dest_i);
	return (count_char);
}
