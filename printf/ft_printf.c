/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:25:29 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/18 14:02:31 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flag	ft_flag_init(void)
{
	t_flag	flag;

	flag.dot = -1;
	flag.minus = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.type = 0;
	flag.width = 0;
	return (flag);
}

int		ft_parse_flag(const char *save, int i, t_flag *flag, va_list arg)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_is_typelist(save[i])
			&& !ft_is_flaglist(save[i]))
			break ;
		if (save[i] == '0' && flag->width == 0 && flag->minus == 0)
			flag->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flag, arg);
		if (save[i] == '-')
			*flag = ft_flag_minus(*flag);
		if (save[i] == '*')
			*flag = ft_flag_width(arg, *flag);
		if (ft_isdigit(save[i]))
			*flag = ft_flag_digit(save[i], *flag);
		if (ft_is_typelist(save[i]))
		{
			flag->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_save(const char *save, va_list arg)
{
	int		i;
	t_flag	flag;
	int		count_char;

	i = 0;
	count_char = 0;
	while (1)
	{
		flag = ft_flag_init();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_parse_flag(save, ++i, &flag, arg);
			if (ft_is_typelist(save[i]))
				count_char += ft_treatment((char)flag.type, flag, arg);
			else if (save[i])
				count_char += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			count_char += ft_putchar(save[i]);
		i++;
	}
	return (count_char);
}

int		ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		arg;
	int			count_char;

	save = ft_strdup((char*)input);
	count_char = 0;
	va_start(arg, input);
	count_char += ft_save(save, arg);
	va_end(arg);
	free((char *)save);
	return (count_char);
}
