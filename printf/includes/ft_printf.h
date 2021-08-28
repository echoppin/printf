/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:43:10 by echoppin          #+#    #+#             */
/*   Updated: 2020/12/18 13:22:43 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int			already_print;
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
}				t_flag;

int				ft_printf(const char *input, ...);
int				ft_width_treat(int width, int minus, int with_zero);
int				ft_treatment(int c, t_flag flag, va_list arg);
int				ft_is_flaglist(int c);
int				ft_is_typelist(int c);
int				ft_string_treat(char *str, t_flag flag);
int				ft_putstrprec(char *str, int prec);
int				ft_putchar(int c);
int				ft_pointer_treat(unsigned long long ull, t_flag flag);
int				ft_percent_treat(t_flag flag);
int				ft_int_treat(int i, t_flag flag);
int				ft_hexa_treat(unsigned int uint, int lower, t_flag flags);
int				ft_flag_dot(const char *save, int start,
				t_flag *flag, va_list arg);
int				ft_char_treat(char c, t_flag flag);
int				ft_uint_treat(unsigned int unsi, t_flag flag);
char			*ft_ull_base(unsigned long long ull, int base);
char			*ft_uitoa(unsigned int n);
char			*ft_str_tolower(char *str);
t_flag			ft_flag_width(va_list arg, t_flag flag);
t_flag			ft_flag_digit(char c, t_flag flag);
t_flag			ft_flag_minus(t_flag flag);

#endif
