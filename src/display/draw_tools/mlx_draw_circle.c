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

void mlx_draw_circle(t_display *display, int radius, int pos[2], int color)
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
				my_mlx_pixel_put(&display->img, j + pos[0], i + pos[1], color);
			j++;
		}
		i++;
	}
}

void mlx_draw_circle_oriented(t_display *display, int radius, double angle, int color, int pos[2])
{
	bool collision = false;
	t_p a;
	t_p b;

	mlx_draw_circle(display, radius, pos, color);
	(void)angle;
	a.x = pos[0];
	a.y = pos[1];

	int i = 0;
	while (!collision)
	{
		i++;
		b.x = pos[0] + cos(angle) * i;
		b.y = pos[1] + sin(angle) * i;
		if (display->map.map[(int)b.y / 40][(int)b.x / 40] == '1')
			collision = true;
	}
	mlx_draw_line(display, a, b, 0x0000FF);
}