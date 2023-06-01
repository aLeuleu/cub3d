/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_opening.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:43:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/01 10:44:02 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_minimap_opening(t_display *display)
{
	if (display->keys[KEY_M])
	{
		if (display->display_mode == GAME)
			display->display_mode = MINIMAP;
		else if (display->display_mode == MINIMAP)
			display->display_mode = MAP;
		else
			display->display_mode = GAME;
		init_map_image(display);
	}
	return (EXIT_SUCCESS);
}

void	init_map_image(t_display *display)
{
	if (display->display_mode == MINIMAP)
		display->size_minimap = display->width / 9;
	else if (display->display_mode == MAP)
	{
		if (display->map.height > display->map.width)
			display->size_minimap = display->map.height * display->map.zoom;
		else
			display->size_minimap = display->map.width * display->map.zoom;
	}
	else
		return ;
	if (display->img_minimap.img)
		mlx_destroy_image(display->mlx, display->img_minimap.img);
	display->img_minimap.img = mlx_new_image(\
			display->mlx, display->size_minimap, display->size_minimap);
	display->img_minimap.addr = mlx_get_data_addr(\
		display->img_minimap.img, \
		&display->img_minimap.bits_per_pixel, \
		&display->img_minimap.line_length, \
		&display->img_minimap.endian);
}
