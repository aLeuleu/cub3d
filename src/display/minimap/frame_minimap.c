/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:04:30 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 14:26:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_frame_minimap(t_display *display)
{
	t_p	start;
	t_p	end;

	start = init_point(0, 0);
	end = init_point(display->size_minimap, 0);
	mlx_draw_line(display, start, end, DARK_GREEN);
	start = init_point(0, 0);
	end = init_point(0, display->size_minimap);
	mlx_draw_line(display, start, end, DARK_GREEN);
	start = init_point(0, display->size_minimap - 1);
	end = init_point(display->size_minimap, display->size_minimap - 1);
	mlx_draw_line(display, start, end, DARK_GREEN);
	start = init_point(display->size_minimap - 1, 0);
	end = init_point(display->size_minimap - 1, display->size_minimap);
	mlx_draw_line(display, start, end, DARK_GREEN);
	return (EXIT_SUCCESS);
}
