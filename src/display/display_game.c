/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/19 14:57:39 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool find_collision(t_display *display, t_p *start, t_p *p_collision, double angle);
static bool check_collision(t_display *display, t_p p, int orientation);
		t_p 	farest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	closest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	add_points(t_p p1, t_p p2); // a mettre dans un bibli
static double floor2(double n);

void angle_routine(t_display *display, double angle, double *tan_angle);

void	display_game(t_display *display)
{
	double lin_len;
	t_p wall_up;
	t_p wall_down;
	double wall_height;
	int count = 0;
	double i;
	t_p start_pos;

	t_p p_collision;
	double angle;
	const double half_height = (double)display->height / 2;
	const double one_on_width =  2/((double)display->width);


	i = -1;
	while ( i <= 1)
	{
		start_pos = display->player.pos;
		angle = display->player.orientation + (M_PI * i/ 6);
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		p_collision = start_pos;
		find_collision(display, &start_pos, &p_collision, angle);
		display->ray_len = sqrt(pow(p_collision.x - display->player.pos.x, 2) + pow(p_collision.y - display->player.pos.y, 2));

		lin_len = display->ray_len * cos(angle - display->player.orientation);
		wall_height = (double)display->height/lin_len;
		if (display->ray_len < 0.1)
			display->ray_len = 0.1;
		wall_up.x = count;
		wall_up.y = half_height - (double)wall_height / 2;
		wall_down.x = wall_up.x;
		wall_down.y = half_height + (double)wall_height / 2;
		display_textures(display, wall_up, wall_down, p_collision);
		i += one_on_width;
		count++;
	}
}

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
	{closest = p1; }
	else
	{closest = p2;}
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

void angle_routine(t_display *display, double angle, double *tan_angle)
{
	(void)display;
	if (angle < 0 || angle > M_PI / 2)
 		printf("ERROR\n");
	*tan_angle = tan(angle);
	if (*tan_angle < 0)
		*tan_angle *= -1;
}

bool check_collision(t_display *display, t_p p, int orientation)
{
	if ((orientation == NW || orientation == SW)  && (int)p.x == p.x) // WEST
		p.x -= 1;
	if ((orientation == NE || orientation == NW)  && (int)p.y == p.y) // NORTH
		p.y -= 1;
	if (p.x < 0 || p.x >= display->map.width || p.y < 0 || p.y >= display->map.height)
		return (true);
	if (display->map.map[(int)(p.y)][(int)(p.x)] == '1')
		return (true);
	return (false);
}

bool	find_collision(t_display *display, t_p *start, t_p *p_collision, double angle)
{
	t_p		ix;
	t_p		iy;
	t_p		tmp;
	bool	collisionx;
	bool	collisiony;
	double tan_angle;
	collisionx = false;
	collisiony = false;
	const double two_pi = 2 * M_PI;
	ix.x = 0;
	ix.y = 0;
	iy.x = 0;
	iy.y = 0;
	
	if (angle > 0 && angle < M_PI_2)
	{
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = ((int)(tmp.x)) + 1;
			ix.y = tmp.y + (ix.x - tmp.x) * tan_angle;
			collisionx = check_collision(display, ix, SE);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = ((int)(tmp.y)) + 1;
			iy.x = tmp.x + (iy.y - tmp.y) / tan_angle;
			collisiony = check_collision(display, iy, SE);
			tmp = iy;
		}
	}
	else if (angle > M_PI_2 && angle < M_PI)
	{
		angle = M_PI - angle;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (floor2(tmp.x));
			ix.y = tmp.y + (tmp.x - ix.x) * tan_angle;
			collisionx = check_collision(display, ix, SW);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = ((int)(tmp.y)) + 1;
			iy.x = tmp.x - (iy.y - tmp.y) / tan_angle;
			collisiony = check_collision(display, iy, SW);
			tmp = iy;
		}
	}
	else if (angle > M_PI && angle < 3 * M_PI_2)
	{
		angle = angle - M_PI;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (floor2(tmp.x));
			ix.y = tmp.y - (tmp.x - ix.x) * tan_angle;
			collisionx = check_collision(display, ix, NW);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = (floor2(tmp.y));
			iy.x = tmp.x - (tmp.y - iy.y) / tan_angle;
			collisiony = check_collision(display, iy, NW);
			tmp = iy;
		}
	}
	else if (angle > 3 * M_PI_2 && angle < two_pi)
	{
		angle = two_pi - angle;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (int)(tmp.x) + 1;
			ix.y = tmp.y - (ix.x - tmp.x) * tan_angle;
			collisionx = check_collision(display, ix, NE);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = floor2(tmp.y);
			iy.x = tmp.x + (tmp.y - iy.y) / tan_angle;
			collisiony = check_collision(display, iy, NE);
			tmp = iy;
		}

	}
	else if (angle == 0 || angle == two_pi)
	{
		tmp = *start;
		while (!collisionx)
		{
			ix.x = (int)(tmp.x) + 1;
			ix.y = tmp.y;
			collisionx = check_collision(display, ix, E);
			tmp = ix;
		}
		iy = ix;
	}
	else if (angle == M_PI_2)
	{
		ix.x = 0;
		ix.y = 0;
		tmp = *start;
		while (!collisiony)
		{
			iy.x = tmp.x;
			iy.y = (int)(tmp.y) + 1;
			collisiony = check_collision(display, iy, S);
			tmp = iy;
		}
		ix = iy;
	}
	else if (angle == M_PI)
	{
		ix.x = (floor2(start->x) );
		ix.y = start->y;

		iy.x = 0;
		iy.y = 0;
		tmp = ix;
		collisionx = check_collision(display, ix, W);
		while (!collisionx)
		{
			ix.x = ((int) (tmp.x) - 1);
			ix.y = tmp.y;
			collisionx = check_collision(display, ix, W);
			tmp = ix;
		}
		iy = ix;
	}
	else if (angle == 3 * M_PI_2)
	{
		iy.x = start->x;
		iy.y = floor2(start->y);
		tmp = iy;
		while (!collisiony)
		{
			iy.x = tmp.x;
			iy.y = (int)(tmp.y) - 1;
			collisiony = check_collision(display, iy, N);
			tmp = iy;
		}
		ix = iy;
	}
	else
	{
		ix.x = 0;
		ix.y = 0;
		iy.x = 0;
		iy.y = 0;
	}
	ix.collision = true;
	iy.collision = true;
	if (ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height)
		ix.collision = false;
	if (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height)
		iy.collision = false;
	if (ix.collision && iy.collision)
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	if (ix.collision)
	{
		*p_collision = ix;
		return (true);
	}
	if (iy.collision)
	{
		*p_collision = iy;
		return (true);
	}
	if ((ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height) \
		&& (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height))
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	return (false);
}

static double floor2(double n)
{
	double	res;

	res = (int) n;
	if (n == (int) n)
		res -= 1;
	return (res);
}
