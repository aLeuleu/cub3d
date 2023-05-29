/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:12:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 14:19:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Initialization function for member variables of the map structure.
 * 
 * @param map Overall structure of the map (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	init_map_struct(t_display *display)
{
	display->map = malloc(sizeof(t_map));
	if (!display->map)
		return (EXIT_FAILURE);
	display->map->nb_parameter_set = 0;
	display->map->path_texture_no = NULL;
	display->map->path_texture_so = NULL;
	display->map->path_texture_we = NULL;
	display->map->path_texture_ea = NULL;
	display->map->texture_no = NULL;
	display->map->texture_so = NULL;
	display->map->texture_we = NULL;
	display->map->texture_ea = NULL;
	display->map->color_c = NULL;
	display->map->color_f = NULL;
	display->map->map = NULL;
	return (EXIT_SUCCESS);
}
