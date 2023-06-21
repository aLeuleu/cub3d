/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/21 17:08:37 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	floor2(double n)
{
	double	res;

	res = (int)n;
	if (n == (int)n)
		res -= 1;
	return (res);
}

t_p	closest_point(t_p start, t_p p1, t_p p2)
{
	t_p		closest;
	double	d1;
	double	d2;

	d1 = sqrt(pow(p1.x - start.x, 2) + pow(p1.y - start.y, 2));
	d2 = sqrt(pow(p2.x - start.x, 2) + pow(p2.y - start.y, 2));
	if (d1 < d2)
		closest = p1;
	else
		closest = p2;
	return (closest);
}
