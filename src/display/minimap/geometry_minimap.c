/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:55:24 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/01 12:17:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put_minimap(t_display *display, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= display->width || y >= display->height)
		return ;
	if (x < 0 || y < 0 || x >= display->size_minimap \
	|| y >= display->size_minimap)
		return ;
	dst = display->img.addr \
	+ (y * display->img.line_length \
	+ x * (display->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw_square_minimap(t_display *display, int side_len, \
			t_p pos, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < side_len)
	{
		j = 0;
		while (j < side_len)
		{
			my_mlx_pixel_put_minimap(display, j + pos.x, i + pos.y, color);
			j++;
		}
		i++;
	}
}

void	mlx_draw_circle_minimap(t_display *display, int radius, \
			t_p pos, int color)
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
				my_mlx_pixel_put_minimap(display, j + pos.x, i + pos.y, color);
			j++;
		}
		i++;
	}
}

void	mlx_draw_circle_player(t_display *display, int radius, \
double orientation, t_p pos)
{
	t_p	a;
	t_p	b;

	mlx_draw_circle_minimap(display, radius, pos, 0x3d4839);
	a.x = pos.x;
	a.y = pos.y;
	b.x = pos.x + cos(orientation) * radius * 2;
	b.y = pos.y + sin(orientation) * radius * 2;
	mlx_draw_line(display, a, b, 0x3d4839);
}

double	offset_minimap(t_display *display, double point, double offset)
{
	double	result;

	result = (point + offset) * display->map.zoom \
			+ (display->size_minimap / 2);
	return (result);
}
