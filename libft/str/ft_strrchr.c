/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:51:45 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:18:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		is_find;
	char	letter;
	size_t	idx;
	size_t	find_idx;
	size_t	len_s;

	is_find = 0;
	letter = (char)c;
	idx = 0;
	len_s = ft_strlen(s) + 1;
	if ((char)c == 0)
		return ((char *) s + ft_strlen(s));
	while (idx <= len_s && s[idx])
	{
		if (s[idx] == letter)
		{	
			find_idx = idx;
			is_find = 1;
		}
		idx++;
	}
	if (is_find)
		return ((char *) s + find_idx);
	return (NULL);
}
