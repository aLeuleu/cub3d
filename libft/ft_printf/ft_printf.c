/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:50:17 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:18:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *format, ...)
{
	int		idx;
	int		count;
	va_list	ap;

	idx = 0;
	count = 0;
	va_start(ap, format);
	while (format[idx] && count != -1)
	{
		if (format[idx] == '%')
		{
			idx++;
			if (format[idx] != '\0')
				ft_display_arg(format[idx], ap, &count);
			else
				return (count);
		}
		else
			ft_putchar_p(format[idx], &count);
		idx++;
	}
	va_end(ap);
	return (count);
}
