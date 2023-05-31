/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 14:16:00 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_window(t_display *display)
{
	free_images(display);
	if (display->mlx_win)
		mlx_destroy_window(display->mlx, display->mlx_win);
	if (OS_LINUX)
		mlx_destroy_display(display->mlx);
	free_map(&display->map);
	free(display->keys);
	free(display->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

