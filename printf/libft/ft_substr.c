/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:06:49 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/28 15:37:45 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if ((size_t)ft_strlen(s) < len)
		len = (size_t)ft_strlen(s);
	while (start-- && *s)
		s++;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(res, s, len + 1);
	return (res);
}
