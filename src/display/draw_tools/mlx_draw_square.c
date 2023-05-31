/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/05/29 15:37:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_draw_square(t_display *display, int side_len, int pos[2], int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < side_len)
	{
		j = 0;
		while (j < side_len)
		{
			my_mlx_pixel_put(display, j + pos[0], i + pos[1], color);
			j++;
		}
		i++;
	}
}