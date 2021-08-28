/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:36:31 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/17 12:01:09 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_part_int(char *str, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.dot >= 0)
	{
		count_char += ft_width_treat(flag.dot, ft_strlen(str), 0);
		count_char += ft_putstrprec(str, flag.dot);
	}
	else
	{
		count_char += ft_putstrprec(str, ft_strlen(str));
	}
	return (count_char);
}

int			ft_string_treat(char *str, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (!str)
		str = "(null)";
	if (flag.dot >= 0 && (size_t)flag.dot > ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		count_char += ft_put_part_int(str, flag);
	if (flag.dot >= 0)
		count_char += ft_width_treat(flag.width, flag.dot, 0);
	else
		count_char += ft_width_treat(flag.width, ft_strlen(str), flag.zero);
	if (flag.minus == 0)
		count_char += ft_put_part_int(str, flag);
	return (count_char);
}
