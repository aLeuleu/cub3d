/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:50 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 14:06:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_tab(char **tab)
{
	int	idx;

	if (!tab)
		return ;
	idx = 0;
	while (tab[idx] != NULL)
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}
