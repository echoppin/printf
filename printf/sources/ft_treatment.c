/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:38:09 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/16 11:04:43 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_typelist(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'i') || (c == 'd')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_is_flaglist(int c)
{
	return ((c == '-') || (c == '.') || (c == '*') || (c == ' ') || c == '0');
}

int	ft_treatment(int c, t_flag flag, va_list arg)
{
	int count_char;

	count_char = 0;
	if (c == 'c')
		count_char = ft_char_treat(va_arg(arg, int), flag);
	else if (c == 's')
		count_char = ft_string_treat(va_arg(arg, char *), flag);
	else if (c == 'p')
		count_char = ft_pointer_treat(va_arg(arg, unsigned long long), flag);
	else if (c == 'i' || c == 'd')
		count_char = ft_int_treat(va_arg(arg, int), flag);
	else if (c == 'x')
		count_char += ft_hexa_treat(va_arg(arg, unsigned int), 1, flag);
	else if (c == 'X')
		count_char += ft_hexa_treat(va_arg(arg, unsigned int), 0, flag);
	else if (c == 'u')
		count_char += ft_uint_treat((unsigned int)
		va_arg(arg, unsigned int), flag);
	else if (c == '%')
		count_char += ft_percent_treat(flag);
	return (count_char);
}
