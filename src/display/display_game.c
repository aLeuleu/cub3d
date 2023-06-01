/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/01 16:55:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool check_collision(t_display *display, t_p start, t_p *i1, t_p *i2, double i);
t_p 	farest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	closest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	add_points(t_p p1, t_p p2); // a mettre dans un bibli

void	display_game(t_display *display)
{
	t_p pos;
	double lin_len;
	int wall_color = 0xFF0000;
	t_p wall_up;
	t_p wall_down;
	double ray_len;
	double wall_height;
	int zoom = display->map.zoom;
	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	int count = 0;
	double i;
	t_p start_pos;
	t_p i1;
	t_p i2;
	t_p p_collision;
	double angle;

	i = -1;
	angle = display->player.orientation - (M_PI / 6);
	while ( i <= 1)
	{
		start_pos = display->player.pos;
		while (!check_collision(display, start_pos, &i1, &i2, angle * i))
		{
//			mlx_draw_circle(display, 1, i1, 0x00ff00);
//			mlx_draw_circle(display, 1, i2, 0x00ff00);
			start_pos = add_points(start_pos, farest_point(start_pos, i1, i2));
		}
		p_collision = closest_point(start_pos, i1, i2);
		mlx_draw_circle(display, 1, p_collision, 0x0000ff);
		ray_len = sqrt(pow(p_collision.x - display->player.pos.x, 2) + pow(p_collision.y - display->player.pos.y, 2));
		lin_len = ray_len * cos(display->player.orientation - display->player.orientation);
		wall_height = (double)display->height/lin_len;
		wall_up.x = count++;
		wall_up.y = (double)display->height / 2 - (double)wall_height / 2;
		wall_down.x = wall_up.x;
		wall_down.y = (double)display->height / 2 + (double)wall_height / 2;
		mlx_draw_line(display, wall_up, wall_down, wall_color);
		i += 1/(double)display->width * 2;
	}

}

//	while ( i < 1)
//	{
//		j = 1;
//		collision = false;
//		while (!collision)
//		{
//			a.x = pos.x + cos(display->player.orientation + angle * i) * j;
//			a.y = pos.y + sin(display->player.orientation + angle * i) * j;
//			if ((int)(a.y / zoom) < 0 || (int)(a.y / zoom) >= display->map.height
//				|| (int)(a.x / zoom) < 0 || (int)(a.x / zoom) >= display->map.width)
//				collision = true;
//			else if (display->map.map[(int)(a.y / zoom)][(int)(a.x / zoom)] == '1')
//				collision = true;
//			j+= 1/(double)display->width * 2;
//		}
//		i += 1/(double)display->width * 2;
//		lin_len = sqrt(pow(a.x - pos.x, 2) + pow(a.y - pos.y, 2));
//
//		double wall_len;
//
//		wall_len = (double)display->height/lin_len;
//		wall_up.x = count++;
//		wall_up.y = (double)display->height / 2 - (double)wall_len / 2;
//		wall_down.x = wall_up.x;
//		wall_down.y = (double)display->height / 2 + (double)wall_len / 2;
//		mlx_draw_line(display, wall_up, wall_down, wall_color);
//	}

t_p 	add_points(t_p p1, t_p p2)
{
	t_p p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return (p3);
}

t_p 	closest_point(t_p start, t_p p1, t_p p2)
{
	t_p closest;

	double d1 = sqrt(pow(p1.x - start.x, 2) + pow(p1.y - start.y, 2));
	double d2 = sqrt(pow(p2.x - start.x, 2) + pow(p2.y - start.y, 2));

	if (d1 < d2)
		closest = p1;
	else
		closest = p2;
	return (closest);
}


t_p 	farest_point(t_p start, t_p p1, t_p p2)
{
	t_p farest;

	double d1 = sqrt(pow(p1.x - start.x, 2) + pow(p1.y - start.y, 2));
	double d2 = sqrt(pow(p2.x - start.x, 2) + pow(p2.y - start.y, 2));

	if (d1 > d2)
		farest = p1;
	else
		farest = p2;
	return (farest);
}

bool check_collision(t_display *display, t_p start, t_p *i1, t_p *i2, double angle)
{
	int tile_size = display->map.zoom;

//	if (display->player.orientation == 0 || display->player.orientation == M_PI)
//		return (false);
	i1->x = (int)(start.x/tile_size) * tile_size + tile_size;
	i1->y = start.y + (i1->x - start.x) * tan(angle);

	i2->y = (int)(start.y/tile_size) * tile_size + tile_size;
	i2->x = start.x/tile_size + (i2->y - start.y) / tan(angle);

	mlx_draw_circle(display, 1, *i1, 0x0000ff); //debug
	mlx_draw_circle(display, 1, *i2, 0x0000ff); //debug
	if (i1->x < 0 || i1->x >= display->map.width || i1->y < 0 || i1->y >= display->map.height)
		return (true);
	if (i2->x < 0 || i2->x >= display->map.width || i2->y < 0 || i2->y >= display->map.height)
		return (true);
	if (display->map.map[(int)(i1->y)][(int)(i1->x)] == '1')
		return (true);
	if (display->map.map[(int)(i2->y)][(int)(i2->x)] == '1')
		return (true);
	return (false);
}
