/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:04:59 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 10:29:46 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (display->map.texture_no)
		mlx_destroy_image(display->mlx, display->map.texture_no);
	if (display->map.texture_so)
		mlx_destroy_image(display->mlx, display->map.texture_so);
	if (display->map.texture_we)
		mlx_destroy_image(display->mlx, display->map.texture_we);
	if (display->map.texture_ea)
		mlx_destroy_image(display->mlx, display->map.texture_ea);
	if (display->img.img)
		mlx_destroy_image(display->mlx, display->img.img);
}
