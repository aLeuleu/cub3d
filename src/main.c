/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:34:44 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_map	map;

	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, 1920, 1080, "Cub3D - 42 project");
	mlx_hook(map.mlx_win, 17, 0, &quit_window, &map);
	mlx_loop(map.mlx);
	return (0);
}
