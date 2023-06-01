/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/01 13:26:56 by lpupier          ###   ########.fr       */
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

int	display_coo_player(t_display *display) //coordoonees
{
	char	*text_x;
	char	*text_y;
	char	*coo_x;
	char	*coo_y;

	coo_x = ft_itoa((int)display->player.pos.x);
	if (!coo_x)
		return (EXIT_FAILURE);
	text_x = ft_strjoin("X: ", coo_x);
	free(coo_x);
	if (!text_x)
		return (EXIT_FAILURE);
	coo_y = ft_itoa((int)display->player.pos.y);
	if (!coo_y)
		return (free(text_x), EXIT_FAILURE);
	text_y = ft_strjoin("Y: ", coo_y);
	free(coo_y);
	if (!text_y)
		return (free(text_x), EXIT_FAILURE);
	mlx_string_put(display->mlx, display->mlx_win, \
		5, display->size_minimap + 22, WHITE, text_x);
	mlx_string_put(display->mlx, display->mlx_win, \
		50, display->size_minimap + 22, WHITE, text_y);
	return (free(text_x), free(text_y), EXIT_SUCCESS);
}
