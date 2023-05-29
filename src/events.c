/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 16:32:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	quit_window(t_display *display)
{
	mlx_destroy_window(display->mlx, display->mlx_win);
	if (OS_LINUX)
		mlx_destroy_display(display->mlx);
	free(display->mlx);
	free_map(&display->map);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
