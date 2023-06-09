/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/21 17:06:56 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	adjust_angle(double *angle)
{
	if (*angle < 0)
		*angle += 2 * M_PI;
	else if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void	angle_routine(double angle, double *tan_angle, int orientation)
{
	if (orientation == NE)
		angle = TWO_PI - angle;
	else if (orientation == SW)
		angle = M_PI - angle;
	else if (orientation == NW)
		angle = angle - M_PI;
	else if (orientation == SE)
		angle = 2 * M_PI - angle;
	*tan_angle = tan(angle);
	if (*tan_angle < 0)
		*tan_angle *= -1;
}

bool	check_collision(t_display *display, t_p p, int orientation)
{
	if ((orientation == NW || orientation == SW) && (int)p.x == p.x)
		p.x -= 1;
	if ((orientation == NE || orientation == NW) && (int)p.y == p.y)
		p.y -= 1;
	if (p.x < 0 || p.x >= display->map.width || p.y < 0
		|| p.y >= display->map.height)
		return (true);
	if (display->map.map[(int)(p.y)][(int)(p.x)] == '1')
		return (true);
	return (false);
}

void	get_orientation(int *orientation, double angle)
{
	if (angle > 0 && angle < M_PI_2)
		*orientation = SE;
	else if (angle > M_PI_2 && angle < M_PI)
		*orientation = SW;
	else if (angle > M_PI && angle < 3 * M_PI_2)
		*orientation = NW;
	else if (angle > 3 * M_PI_2 && angle < 2 * M_PI)
		*orientation = NE;
	else if (angle == 0 || angle == 2 * M_PI)
		*orientation = E;
	else if (angle == M_PI_2)
		*orientation = S;
	else if (angle == M_PI)
		*orientation = W;
	else if (angle == 3 * M_PI_2)
		*orientation = N;
}

bool	orientation_is_cardinal(int orientation)
{
	return (orientation == N || \
			orientation == S || \
			orientation == E || \
			orientation == W);
}
