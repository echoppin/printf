/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_treat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:28:25 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 10:53:30 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_char_treat(char c, t_flag flag)
{
	int	count_char;

	count_char = 0;
	if (flag.minus == 1)
		ft_putchar(c);
	count_char = ft_width_treat(flag.width, 1, 0);
	if (flag.minus == 0)
		ft_putchar(c);
	return (count_char + 1);
}
