/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:33:24 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 10:58:22 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_percent_treat(t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.minus == 1)
		count_char += ft_putstrprec("%", 1);
	count_char += ft_width_treat(flag.width, 1, flag.zero);
	if (flag.minus == 0)
		count_char += ft_putstrprec("%", 1);
	return (count_char);
}
