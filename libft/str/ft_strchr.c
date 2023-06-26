/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:29:34 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:18:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;
	size_t	idx;
	size_t	len_s;

	letter = (char)c;
	idx = 0;
	len_s = ft_strlen(s) + 1;
	if ((char)c == 0)
		return ((char *) s + ft_strlen(s));
	while (idx <= len_s && s[idx])
	{
		if (s[idx] == letter)
			return ((char *) s + idx);
		idx++;
	}
	return (NULL);
}
