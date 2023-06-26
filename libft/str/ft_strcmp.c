/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:37 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 13:00:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			idx;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	idx = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (new_s1[idx] && new_s2[idx] && new_s1[idx] == new_s2[idx])
		idx++;
	return (new_s1[idx] - new_s2[idx]);
}
