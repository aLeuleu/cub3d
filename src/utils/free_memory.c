/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:04:59 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/15 11:29:10 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	free(map->path_texture_no);
	free(map->path_texture_so);
	free(map->path_texture_we);
	free(map->path_texture_ea);
	free(map->color_f_raw);
	free(map->color_c_raw);
	ft_free_tab(map->map);
}

void	free_images(t_display *display)
{
	if (display->map.texture_no.img)
		mlx_destroy_image(display->mlx, display->map.texture_no.img);
	if (display->map.texture_so.img)
		mlx_destroy_image(display->mlx, display->map.texture_so.img);
	if (display->map.texture_we.img)
		mlx_destroy_image(display->mlx, display->map.texture_we.img);
	if (display->map.texture_ea.img)
		mlx_destroy_image(display->mlx, display->map.texture_ea.img);
	if (display->img.img)
		mlx_destroy_image(display->mlx, display->img.img);
}
