/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 17:22:08 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	quit_window(t_display *display)
{
	mlx_destroy_image(display->mlx, display->map.texture_no);
	mlx_destroy_image(display->mlx, display->map.texture_so);
	mlx_destroy_image(display->mlx, display->map.texture_we);
	mlx_destroy_image(display->mlx, display->map.texture_ea);
	mlx_destroy_image(display->mlx, display->img.img);
	mlx_destroy_window(display->mlx, display->mlx_win);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
	free_map(&display->map);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
