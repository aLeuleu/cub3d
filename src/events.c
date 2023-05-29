/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:12 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 19:01:10 by lpupier          ###   ########.fr       */
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
	if (OS_LINUX)
		mlx_destroy_display(display->mlx);
	free_map(&display->map);
	free(display->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	check_keycode(int keycode, t_display *display)
{
	if (keycode == KEY_W)
		display->player.pos_y -= 1;
	else if (keycode == KEY_S)
		display->player.pos_y += 1;
	else if (keycode == KEY_A)
		display->player.pos_x -= 1;
	else if (keycode == KEY_D)
		display->player.pos_x += 1;
	return (EXIT_SUCCESS);
}

int	check_mousecode(int mousecode, int x, int y, t_display *display)
{
	(void)display;
	(void)x;
	(void)y;
	printf("# define MOUSE_ %d\n", mousecode);
	return (EXIT_SUCCESS);
}
