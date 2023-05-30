/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:19 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 11:44:58 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keycode(int keycode, t_display *display)
{
	display->keys[keycode] = 1;
	player_movements(display);
	return (EXIT_SUCCESS);
}

int	check_keycode_up(int keycode, t_display *display)
{
	display->keys[keycode] = 0;
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
