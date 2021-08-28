/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_treat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:41:47 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 11:09:03 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_width_treat(int width, int minus, int with_zero)
{
	int	count_char;

	count_char = 0;
	while (width - minus > 0)
	{
		if (with_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count_char++;
	}
	return (count_char);
}
