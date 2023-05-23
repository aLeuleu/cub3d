/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/23 16:38:36 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	quit_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}
