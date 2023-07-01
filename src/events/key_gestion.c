/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:19 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/01 18:25:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keycode(int keycode, t_display *display)
{
	if (keycode == KEY_ESCAPE)
		quit_window(display);
	else if (keycode == 65361)
		display->keys[KEY_LEFT] = 1;
	else if (keycode == 65363)
		display->keys[KEY_RIGHT] = 1;
	else if (keycode <= 256)
		display->keys[keycode] = 1;
	check_minimap_opening(display);
	return (0);
}

int	check_keycode_up(int keycode, t_display *display)
{
	if (keycode == 65361)
		display->keys[KEY_LEFT] = 0;
	else if (keycode == 65363)
		display->keys[KEY_RIGHT] = 0;
	if (keycode <= 256)
		display->keys[keycode] = 0;
	return (0);
}

int	check_mousecode(int x, int y, t_display *display)
{
	if (display->keys[KEY_LEFT] || display->keys[KEY_RIGHT] \
	|| display->keys[KEY_Q] || display->keys[KEY_E])
		return (1);
	if (x < display->width / 2)
		display->player.orientation -= 0.02;
	else if (x > display->width / 2)
		display->player.orientation += 0.02;
	if (y < display->height / 2)
		display->player.pov_vertical += 10;
	else if (y > display->height / 2)
		display->player.pov_vertical -= 10;
	if (OS_LINUX)
	{
		mlx_mouse_move(\
		display->mlx, \
		display->mlx_win, \
		display->width / 2, \
		display->height / 2);
	}
	return (0);
}
