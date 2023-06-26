/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:00:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:18:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;
	size_t	idx;

	if (s)
	{
		size = ft_strlen(s);
		idx = 0;
		while (idx < size)
		{
			ft_putchar_fd(s[idx], fd);
			idx++;
		}
	}
}
