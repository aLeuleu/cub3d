/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by alevra            #+#    #+#             */
/*   Updated: 2023/06/01 13:33:08 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void minimap_raycasting(t_display *display, int zoom);

static double	offset_minimap(t_display *display, double point, double offset)
{
	double	result;

	result = (point + offset) * display->map.zoom \
			+ (display->size_minimap / 2);
	return (result);
}

static void	raycasting(t_display *display, int zoom)
{
	t_p		pos;
	t_p		a;
	double	angle;
	double	i;
	int		j;
	bool	collision;

	angle = M_PI / 6;
	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	i = -1;
	while (i < 1)
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
		if (display->display_mode == MAP)
			mlx_draw_line_minimap(display, pos, a, WHITE);
	}
}

void	mlx_draw_fov(t_display *display, int zoom)
{
	t_p	pos;
	t_p	a;
	t_p	b;

	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	a.x = pos.x + cos(display->player.orientation - M_PI / 6) * 100;
	a.y = pos.y + sin(display->player.orientation - M_PI / 6) * 100;
	b.x = pos.x + cos(display->player.orientation + M_PI / 6) * 100;
	b.y = pos.y + sin(display->player.orientation + M_PI / 6) * 100;
	if (display->display_mode == MAP)
	{
		mlx_draw_line_minimap(display, pos, a, RED);
		mlx_draw_line_minimap(display, pos, b, RED);
	}
}

void	draw_player(t_display *display, int zoom)
{
	t_p	pos;

	if (display->display_mode == MINIMAP)
	{
		pos.x = display->size_minimap / 2;
		pos.y = display->size_minimap / 2;
	}
	else
	{
		pos.x = display->player.pos.x * zoom;
		pos.y = display->player.pos.y * zoom;
	}
	mlx_draw_circle_player(display, zoom / 2, display->player.orientation, RED, pos);
	mlx_draw_fov(display, zoom);
	raycasting(display, zoom);
}

void	display_minimap(t_display *display)
{
	int	line;
	int	column;
	t_p	pos;
	t_p	square;

	square.x = 0;
	square.y = 0;
	mlx_draw_square_minimap(display, display->size_minimap + 1, square, BLACK);
	line = -1;
	while (++line < display->map.height)
	{
		column = 0;
		while (column < display->map.width)
		{
			if (display->display_mode == MINIMAP)
			{
				pos.x = offset_minimap(display, column, display->offset.x);
				pos.y = offset_minimap(display, line, display->offset.y);
			}
			else
			{
				pos.x = column * display->map.zoom;
				pos.y = line * display->map.zoom;
			}
			if (display->map.map[line][column] == '1')
				mlx_draw_square_minimap(display, display->map.zoom, pos, DARK_BLUE);
			else if (display->map.map[line][column] == '0' || ft_strchr("NSWE", display->map.map[line][column]))
				mlx_draw_square_minimap(display, display->map.zoom, pos, LIGHT_BLUE);
			column++;
		}
	}
	draw_player(display, display->map.zoom);
	draw_frame_minimap(display);
	mlx_put_image_to_window(\
		display->mlx, display->mlx_win, display->img_minimap.img, 0, 0);
}

void minimap_raycasting(t_display *display, int zoom)
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
			mlx_draw_circle(display, 1, a, 0x00FF00);
		}
		i += 0.01;
		//mlx_draw_line(display, pos, a, WHITE);
	}
}