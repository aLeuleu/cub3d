/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:06:17 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:17:39 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	idx = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (new_s1[idx] == new_s2[idx])
			idx++;
		else
		{
			if (idx < n)
				return (new_s1[idx] - new_s2[idx]);
			return (0);
		}
	}
	return (0);
}
