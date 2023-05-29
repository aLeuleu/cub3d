/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 18:02:45 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * The function destroys all images and windows created by the program
 * and frees allocated memory before exiting.
 * 
 * @param display The parameter "display" is a pointer to a struct of type "t_display".
 * 
 * @return (int) Return EXIT_SUCCESS pr EXIT_FAILURE
 */
int	quit_window(t_display *display)
{
	free_images(display);
	if (display->mlx_win)
		mlx_destroy_window(display->mlx, display->mlx_win);
	mlx_destroy_display(display->mlx);
	free_map(&display->map);
	free(display->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
