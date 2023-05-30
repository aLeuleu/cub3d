/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by alevra            #+#    #+#             */
/*   Updated: 2023/05/29 16:32:03 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_minimap(t_display *display)
{
	int	line;
	int	column;
	int zoom;
	int pos[2] = {0, 0};

	line = 0;
	zoom = 40;
	while (line < display->map.height)
	{
		column = 0;
		while (column < display->map.width)
		{
			pos[0] = column * zoom;
			pos[1] = line * zoom;
			if (display->map.map[line][column] == '1')
				mlx_draw_square(display, zoom, pos, 0xDDDD00);
			column++;
		}
		line++;
	}
	draw_player(display, zoom);
}

void	draw_player(t_display *display, int zoom)
{
	t_p pos;

	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	mlx_draw_circle_oriented(display, zoom / 2, display->player.orientation, 0xFF0000, pos);
	mlx_draw_fov(display, zoom);
}

void	mlx_draw_fov(t_display *display, int zoom)
{
	t_p pos;
	t_p a;
	t_p b;

	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	a.x = pos.x + cos(display->player.orientation - M_PI / 6) * 100;
	a.y = pos.y + sin(display->player.orientation - M_PI / 6) * 100;
	b.x = pos.x + cos(display->player.orientation + M_PI / 6) * 100;
	b.y = pos.y + sin(display->player.orientation + M_PI / 6) * 100;
//	mlx_draw_line(display, a, b, 0xFFFFFF);
	mlx_draw_line(display, pos, a, 0xFFFFFF);
	mlx_draw_line(display, pos, b, 0xFFFFFF);

}
