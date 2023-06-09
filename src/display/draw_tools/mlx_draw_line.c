/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/19 14:14:42 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

void	mlx_draw_line(t_display *display, t_p a, t_p b, int color)
{
	int		i;
	int		steps;
	float	x;
	float	y;
	t_p		to_draw;

	steps = ft_max(fabs(b.x - a.x), fabs(b.y - a.y));
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		to_draw.x = round(x);
		to_draw.y = round(y);
		my_mlx_pixel_put(display, to_draw.x, to_draw.y, color);
		x += (b.x - a.x) / (float)steps;
		y += (b.y - a.y) / (float)steps;
		i++;
	}
}

void	mlx_draw_vertical_lines(t_display *display, t_p up, t_p down, int color)
{
	if (down.y < up.y)
		return (mlx_draw_vertical_lines(display, down, up, color));
	while (up.y <= down.y)
	{
		my_mlx_pixel_put(display, up.x, up.y, color);
		up.y ++;
	}
}
