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

void raycasting(t_display *display, int zoom);

void	display_minimap(t_display *display)
{
	int	line;
	int	column;
	int zoom;
	int pos[2] = {0, 0};

	line = 0;
	zoom = display->map.zoom;
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
	raycasting(display, zoom);
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
	mlx_draw_line(display, pos, a, 0x0000FF);
	mlx_draw_line(display, pos, b, 0x0000FF);

}

void raycasting(t_display *display, int zoom)
{
	t_p pos;
	t_p a;
	double angle = M_PI / 6;
	double i;
	int	j;
	bool collision;

	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	i = -1;
	while ( i < 1)
	{
		j = 1;
		collision = false;
		while (!collision)
		{
			a.x = pos.x + cos(display->player.orientation + angle * i) * j;
			a.y = pos.y + sin(display->player.orientation + angle * i) * j;
			if ((int)(a.y / zoom) < 0 || (int)(a.y / zoom) >= display->map.height
				|| (int)(a.x / zoom) < 0 || (int)(a.x / zoom) >= display->map.width)
				collision = true;
			else if (display->map.map[(int)(a.y / zoom)][(int)(a.x / zoom)] == '1')
				collision = true;
			j++;
		}
		i += 0.01;
		mlx_draw_line(display, pos, a, 0xFFFFFF);
	}


}