/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:12:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/26 13:05:04 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_keys(t_display *display)
{
	int	idx;

	idx = -1;
	while (++idx < 256)
		display->keys[idx] = 0;
}

int	init_display_struct(t_display *display)
{
	display->mlx = mlx_init();
	display->mlx_win = NULL;
	display->keys = malloc(sizeof(int) * 256);
	if (!display->keys)
		return (EXIT_FAILURE);
	init_keys(display);
	display->width = 1600;
	display->height = 900;
	display->display_mode = GAME;
	display->size_minimap = display->width / 9;
	init_map_image(display);
	display->offset.x = 0;
	display->offset.y = 0;
	display->img.img = mlx_new_image(\
		display->mlx, display->width, display->height);
	display->img.addr = mlx_get_data_addr(\
		display->img.img, \
		&display->img.bits_per_pixel, \
		&display->img.line_length, \
		&display->img.endian);
	return (EXIT_SUCCESS);
}

int	init_map_struct(t_map *map)
{
	map->nb_parameter_set = 0;
	map->path_texture_no = NULL;
	map->path_texture_so = NULL;
	map->path_texture_we = NULL;
	map->path_texture_ea = NULL;
	map->texture_no.img = NULL;
	map->texture_so.img = NULL;
	map->texture_we.img = NULL;
	map->texture_ea.img = NULL;
	map->color_c_raw = NULL;
	map->color_f_raw = NULL;
	map->color_c = 0;
	map->color_f = 0;
	map->map = NULL;
	map->zoom = 1;
	return (EXIT_SUCCESS);
}

void	init_player(t_display *display)
{
	display->player.fov = 60;
	display->player.speed = 0.1;
}
