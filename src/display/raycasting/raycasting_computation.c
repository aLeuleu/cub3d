/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_computation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/21 17:06:08 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_cardinal_collision(t_p *point, t_display *display,
		int orientation)
{
	t_p		tmp;
	bool	collision;

	tmp = display->player.pos;
	collision = false;
	while (!collision)
	{
		if (orientation == N)
			north_formula(point, &tmp);
		else if (orientation == S)
			south_formula(point, &tmp);
		else if (orientation == E)
			east_formula(point, &tmp);
		else if (orientation == W)
			west_formula(point, &tmp);
		collision = check_collision(display, *point, orientation);
		tmp = *point;
	}
}

void	compute_points_untill_collision(t_p *ix, t_p *iy, t_display *display,
		double angle)
{
	int		orientation;
	double	tan_angle;

	get_orientation(&orientation, angle);
	angle_routine(angle, &tan_angle, orientation);
	if (orientation_is_N_or_S_or_E_or_W(orientation))
	{
		compute_cardinal_collision(ix, display, orientation);
		iy = ix;
	}
	else
	{
		compute_x_points_untill_collision(ix, &tan_angle, display, orientation);
		compute_y_points_untill_collision(iy, &tan_angle, display, orientation);
	}
	ix->collision = true;
	iy->collision = true;
}

void	compute_x_points_untill_collision(t_p *point, const double *tan_angle,
		t_display *display, int orientation)
{
	t_p		tmp;
	bool	collision;

	tmp = display->player.pos;
	collision = false;
	while (!collision)
	{
		if (orientation == NW || orientation == SW)
			point->x = floor2(tmp.x);
		else if (orientation == NE || orientation == SE)
			point->x = ((int)(tmp.x)) + 1;
		if (orientation == NW)
			point->y = tmp.y - (tmp.x - point->x) * (*tan_angle);
		else if (orientation == NE)
			point->y = tmp.y - (point->x - tmp.x) * (*tan_angle);
		else if (orientation == SW)
			point->y = tmp.y + (tmp.x - point->x) * (*tan_angle);
		else if (orientation == SE)
			point->y = tmp.y + (point->x - tmp.x) * (*tan_angle);
		collision = check_collision(display, *point, orientation);
		tmp = *point;
	}
}

void	compute_y_points_untill_collision(t_p *point, const double *tan_angle,
		t_display *display, int orientation)
{
	t_p		tmp;
	bool	collision;

	tmp = display->player.pos;
	collision = false;
	while (!collision)
	{
		if (orientation == SW || orientation == SE)
			point->y = (int)(tmp.y) + 1;
		else if (orientation == NE || orientation == NW)
			point->y = floor2(tmp.y);
		if (orientation == NW)
			point->x = tmp.x - (tmp.y - point->y) / (*tan_angle);
		else if (orientation == NE)
			point->x = tmp.x + (tmp.y - point->y) / (*tan_angle);
		else if (orientation == SW)
			point->x = tmp.x - (point->y - tmp.y) / (*tan_angle);
		else if (orientation == SE)
			point->x = tmp.x + (point->y - tmp.y) / (*tan_angle);
		collision = check_collision(display, *point, orientation);
		tmp = *point;
	}
}