/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:35:42 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 11:00:44 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstrprec(char *str, int prec)
{
	int	count_char;

	count_char = 0;
	while (str[count_char] && count_char < prec)
		ft_putchar(str[count_char++]);
	return (count_char);
}
