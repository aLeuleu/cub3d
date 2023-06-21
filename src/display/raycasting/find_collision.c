/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/21 17:05:31 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool is_out_of_bonds(const t_display *display, t_p *p);

static bool is_out_of_bonds(const t_display *display, t_p *p)
{
	return (*p).x < 0 || (*p).x >= display->map.width || (*p).y < 0
		   || (*p).y >= display->map.height;
}

bool	find_collision(t_display *display, t_p *start, t_p *p_collision,
			   double angle)
{
	t_p	ix;
	t_p	iy;

	compute_points_untill_collision(&ix, &iy, display, angle);
	if (is_out_of_bonds(display, &ix))
		ix.collision = false;
	if (is_out_of_bonds(display, &iy))
		iy.collision = false;
	if (ix.collision && iy.collision)
		*p_collision = closest_point(*start, ix, iy);
	else if (ix.collision)
		*p_collision = ix;
	else if (iy.collision)
		*p_collision = iy;
	if (ix.collision || iy.collision)
		return (true);
	if (is_out_of_bonds(display, &ix) && is_out_of_bonds(display, &iy))
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	return (false);
}
