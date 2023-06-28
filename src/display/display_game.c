/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/21 17:04:47 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compute_walls_and_display_texture(t_display *display, double angle, \
				int count, t_p *p_collision);
static void	record_closest_wall(t_display *display);

void	display_game(t_display *display)
{
	int				count;
	double			i;
	t_p				start_pos;
	t_p				p_collision;
	double			angle;

	count = 0;
	i = -1;
	display->player.closest_wall = 3;
	while (i <= 1)
	{
		start_pos = display->player.pos;
		angle = display->player.orientation + (M_PI * i / 6);
		adjust_angle(&angle);
		p_collision = start_pos;
		find_collision(display, &start_pos, &p_collision, angle);
		display->ray_len = sqrt(pow(p_collision.x - display->player.pos.x, 2) \
		+ pow(p_collision.y - display->player.pos.y, 2));
		record_closest_wall(display);
		compute_walls_and_display_texture(display, angle, count++, \
		&p_collision);
		i += 2 / ((double)display->width);
	}
}

void	record_closest_wall(t_display *display)
{
	if (display->ray_len < display->player.closest_wall)
		display->player.closest_wall = display->ray_len;
}

void	compute_walls_and_display_texture(t_display *display, double angle,
		int count, t_p *p_collision)
{
	t_p				wall_up;
	t_p				wall_down;
	const double	half_height = (double)display->height / 2;
	const double	wall_height = (double)display->height / \
	(display->ray_len * cos(angle - display->player.orientation));

	if (display->ray_len < 0.1)
		display->ray_len = 0.1;
	wall_up.x = count;
	wall_up.y = half_height - (double)wall_height / 2;
	wall_down.x = wall_up.x;
	wall_down.y = half_height + (double)wall_height / 2;
	display_textures(display, wall_up, wall_down, (*p_collision));
}
