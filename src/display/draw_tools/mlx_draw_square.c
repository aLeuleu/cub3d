/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/05/26 16:06:23 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_draw_square(t_display *display, int x, int y, int pos[2], int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mlx_pixel_put(display->mlx, display->mlx_win, j + pos[0], i + pos[1], color);
			j++;
		}
		i++;
	}
}