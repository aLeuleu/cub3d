/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by alevra            #+#    #+#             */
/*   Updated: 2023/06/20 16:30:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player(t_display *display, int zoom)
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
	mlx_draw_circle_player(display, zoom / 2, \
		display->player.orientation, 0x3d4839, pos);
}

static void	minimap_style(t_display *display, int line, int column, t_p pos)
{
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
				mlx_draw_square_minimap(display, \
					display->map.zoom, pos, DARK_GREEN);
			else if (display->map.map[line][column] == '0' \
			|| ft_strchr("NSWE", display->map.map[line][column]))
				mlx_draw_square_minimap(display, \
					display->map.zoom, pos, LIGHT_GREEN);
			column++;
		}
	}
}

void	display_minimap(t_display *display)
{
	int	line;
	int	column;
	t_p	pos;

	line = -1;
	column = 0;
	pos.x = 0;
	pos.y = 0;
	display->map.zoom = 7 * display->width / 1280;
	minimap_style(display, line, column, pos);
	draw_player(display, display->map.zoom);
	if (display->display_mode == MINIMAP)
		draw_frame_minimap(display);
}
