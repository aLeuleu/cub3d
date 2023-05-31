/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:03:53 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 15:43:43 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= display->width || y >= display->height)
		return ;
	dst = display->img.addr + (y * display->img.line_length + x * (display->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
