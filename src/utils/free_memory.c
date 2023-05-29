/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:04:59 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 16:05:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map)
{
	free(map->path_texture_no);
	free(map->path_texture_so);
	free(map->path_texture_we);
	free(map->path_texture_ea);
	free(map->color_f);
	free(map->color_c);
}
