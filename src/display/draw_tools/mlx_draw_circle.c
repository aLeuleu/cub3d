/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_circle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/05/29 15:37:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_draw_circle(t_display *display, int radius, t_p pos, int color)
{
	int	i;
	int	j;

	i = -radius;
	while (i < radius)
	{
		j = -radius;
		while (j < radius)
		{
			if (i * i + j * j <= radius * radius)
				my_mlx_pixel_put(&display->img, j + pos.x, i + pos.y, color);
			j++;
		}
		i++;
	}
}

void mlx_draw_circle_oriented(t_display *display, int radius, double orientation, int color, t_p pos)
{
	bool collision = false;
	t_p a;
	t_p b;

	mlx_draw_circle(display, radius, pos, color);
	(void)orientation;
	a.x = pos.x;
	a.y = pos.y;

	int i = 0;
	while (!collision)
	{
		i++;
		b.x = pos.x + cos(orientation) * i;
		b.y = pos.y + sin(orientation) * i;
		if (display->map.map[(int)b.y / 40][(int)b.x / 40] == '1')
			collision = true;
	}
	mlx_draw_line(display, a, b, 0xFF1111);
}