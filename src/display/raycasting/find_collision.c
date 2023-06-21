/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/19 14:57:39 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	find_collision(t_display *display, t_p *start, t_p *p_collision, double angle)
{
	t_p		ix;
	t_p		iy;

	compute_points_untill_collision(&ix, &iy, display, angle);
	if (ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height)
		ix.collision = false;
	if (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height)
		iy.collision = false;
	if (ix.collision && iy.collision)
		*p_collision = closest_point(*start, ix, iy);
	else if (ix.collision)
		*p_collision = ix;
	else if (iy.collision)
		*p_collision = iy;
	if (ix.collision || iy.collision)
		return (true);
	if ((ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height) \
		&& (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height))
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	return (false);
}