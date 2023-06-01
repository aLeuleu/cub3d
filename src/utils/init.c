/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:12:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/01 09:46:45 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Initialization function for member variables of the display structure.
 * 
 * @param display General structure for screen display (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	init_display_struct(t_display *display)
{
	int	idx;

	display->keys = malloc(sizeof(int) * 256);
	if (!display->keys)
		return (EXIT_FAILURE);
	idx = -1;
	while (++idx < 256)
		display->keys[idx] = 0;
	display->display_mode = MINIMAP;
	display->width = 1920;
	display->height = 1080;
	display->size_minimap = display->width / 9;
	display->offset.x = 0;
	display->offset.y = 0;
	display->mlx = mlx_init();
	display->img.img = mlx_new_image(\
		display->mlx, display->width, display->height);
	display->img.addr = mlx_get_data_addr(\
		display->img.img, \
		&display->img.bits_per_pixel, \
		&display->img.line_length, \
		&display->img.endian);
	display->img_minimap.img = mlx_new_image(\
		display->mlx, display->size_minimap, display->size_minimap);
	display->img_minimap.addr = mlx_get_data_addr(\
		display->img_minimap.img, \
		&display->img_minimap.bits_per_pixel, \
		&display->img_minimap.line_length, \
		&display->img_minimap.endian);
	display->mlx_win = NULL;
	return (EXIT_SUCCESS);
}

/**
 * @brief Initialization function for member variables of the map structure.
 * 
 * @param display General structure for screen display (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	init_map_struct(t_map *map)
{
	map->nb_parameter_set = 0;
	map->path_texture_no = NULL;
	map->path_texture_so = NULL;
	map->path_texture_we = NULL;
	map->path_texture_ea = NULL;
	map->texture_no = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_ea = NULL;
	map->color_c_raw = NULL;
	map->color_f_raw = NULL;
	map->color_c = 0;
	map->color_f = 0;
	map->map = NULL;
	map->zoom = 10;
	return (EXIT_SUCCESS);
}

void	init_player(t_display *display)
{
	display->player.fov = 60;
	display->player.speed = 1;
}
