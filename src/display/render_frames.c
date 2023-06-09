/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:43 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/01 18:31:54 by lpupier          ###   ########.fr       */
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
	draw_half_upper(display, display->map.color_c);
	draw_half_down(display, display->map.color_f);
	display_game(display);
	player_movements(display);
	mlx_put_image_to_window(\
		display->mlx, display->mlx_win, display->img.img, 0, 0);
	if (display->display_mode == MAP || display->display_mode == MINIMAP)
		display_minimap(display);
	return (EXIT_SUCCESS);
}

void	draw_half_upper(t_display *display, int color)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < display->width)
	{
		while (y < display->height / 2 + display->player.pov_vertical)
		{
			my_mlx_pixel_put(display, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	draw_half_down(t_display *display, int color)
{
	int	x;
	int	y;

	y = display->height / 2;
	x = 0;
	while (x < display->width)
	{
		while (y + display->player.pov_vertical < display->height)
		{
			my_mlx_pixel_put(display, x, \
			y + display->player.pov_vertical, color);
			y++;
		}
		y = display->height / 2;
		x++;
	}
}
