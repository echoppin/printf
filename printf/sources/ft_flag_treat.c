/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_treat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:29:37 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:54 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flag	ft_flag_minus(t_flag flag)
{
	flag.minus = 1;
	flag.zero = 0;
	return (flag);
}

t_flag	ft_flag_digit(char c, t_flag flag)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = (flag.width * 10) + (c - '0');
	return (flag);
}

t_flag	ft_flag_width(va_list arg, t_flag flag)
{
	flag.star = 1;
	flag.width = va_arg(arg, int);
	if (flag.width < 0)
	{
		flag.minus = 1;
		flag.width *= -1;
	}
	return (flag);
}

int		ft_flag_dot(const char *save, int start, t_flag *flag, va_list arg)
{
	int i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flag->dot = va_arg(arg, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(save[i]))
			flag->dot = (flag->dot * 10) + (save[i++] - '0');
	}
	return (i);
}
