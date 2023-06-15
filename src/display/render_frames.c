/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:43 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/01 16:57:40 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_half_upper(t_display *display, int color);
static void	draw_half_down(t_display *display, int color);

int	render_frames(t_display *display)
{
	display->offset.x = -display->player.pos.x;
	display->offset.y = -display->player.pos.y;
	ft_memset(display->img.addr, 0, display->height * display->img.line_length);
	int floor_color = 0xB3D89C ;
	int skycolor = 0x4E6CE4;
	if (display->display_mode == MINIMAP)
	{
		ft_memset(display->img.addr, 0, display->height * display->img.line_length);
		display_minimap(display);
	}
	//draw half upper image into sky_color
	draw_half_upper(display, skycolor);
	//draw half lower image into floor_color
	draw_half_down(display, floor_color);
	display_game(display);
	player_movements(display);
	mlx_put_image_to_window(\
		display->mlx, display->mlx_win, display->img.img, 0, 0);
	if (display->display_mode == MAP || display->display_mode == MINIMAP)
	{
		ft_memset(display->img_minimap.addr, 0, \
			display->size_minimap * display->size_minimap);
		display_minimap(display);
//		display_coo_player(display);
		display_debug(display);
	}
	return (EXIT_SUCCESS);
}

void draw_half_upper(t_display *display, int color)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (x < display->width)
	{
		while (y < display->height / 2)
		{
			my_mlx_pixel_put(display, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void draw_half_down(t_display *display, int color)
{
	int x;
	int y;

	y = display->height / 2;
	x = 0;
	while (x < display->width)
	{
		while (y < display->height)
		{
			my_mlx_pixel_put(display, x, y, color);
			y++;
		}
		y = display->height / 2;
		x++;
	}
}