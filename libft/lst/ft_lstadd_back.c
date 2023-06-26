/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:36:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:17:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elt;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			elt = ft_lstlast(*lst);
			elt -> next = new;
		}
	}
}
