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

static size_t		ft_max(size_t a, size_t b)
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

	steps = ft_max(abs(b.x - a.x), abs(b.y - a.y));
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		to_draw.x = round(x);
		to_draw.y = round(y);
		my_mlx_pixel_put(&display->img, to_draw.x, to_draw.y, color);
		x += (b.x - a.x) / (float)steps;
		y += (b.y - a.y) / (float)steps;
		i++;
	}
}