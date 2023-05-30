/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:12:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 15:33:31 by lpupier          ###   ########.fr       */
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
	ft_memset(display->keys, 0, 70000);
	display->width = 1920;
	display->height = 1080;
	display->mlx = mlx_init();
	display->img.img = mlx_new_image(\
		display->mlx, display->width, display->height);
	display->img.addr = mlx_get_data_addr(\
		display->img.img, \
		&display->img.bits_per_pixel, \
		&display->img.line_length, \
		&display->img.endian);
	display->mlx_win = NULL;
	return (EXIT_SUCCESS);
}

/**
 * @brief Initialization function for member variables of the map structure.
 * 
 * @param display General structure for screen display (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	init_map_struct(t_display *display)
{
	display->map.nb_parameter_set = 0;
	display->map.path_texture_no = NULL;
	display->map.path_texture_so = NULL;
	display->map.path_texture_we = NULL;
	display->map.path_texture_ea = NULL;
	display->map.texture_no = NULL;
	display->map.texture_so = NULL;
	display->map.texture_we = NULL;
	display->map.texture_ea = NULL;
	display->map.color_c = NULL;
	display->map.color_f = NULL;
	display->map.map = NULL;
	return (EXIT_SUCCESS);
}

void	init_player(t_display *display)
{
	display->player.fov = 60;
	display->player.speed = 1;
}
