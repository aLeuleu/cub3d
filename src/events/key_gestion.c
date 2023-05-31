/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:19 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 15:21:43 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keycode(int keycode, t_display *display)
{
	if (keycode == KEY_ESCAPE)
		quit_window(display);
	else if (keycode <= 256)
		display->keys[keycode] = 1;
	check_minimap_opening(display);
	return (0);
}

int	check_keycode_up(int keycode, t_display *display)
{
	if (keycode <= 256)
		display->keys[keycode] = 0;
	return (0);
}

int	check_mousecode(int mousecode, int x, int y, t_display *display)
{
	(void)mousecode;
	(void)display;
	(void)x;
	(void)y;
	return (0);
}
