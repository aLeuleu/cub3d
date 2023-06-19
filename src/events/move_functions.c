/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:54:05 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 13:45:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_up(t_display *display, double *new_pos_x, double *new_pos_y)
{
	double	speed;

	speed = display->player.speed;
	if (display->keys[KEY_W])
	{
		*new_pos_y = *new_pos_y \
			- speed * sin(display->player.orientation + M_PI);
		*new_pos_x = *new_pos_x \
			- speed * cos(display->player.orientation + M_PI);
	}
	return (EXIT_FAILURE);
}

int	move_down(t_display *display, double *new_pos_x, double *new_pos_y)
{
	double	speed;

	speed = display->player.speed;
	if (display->keys[KEY_S])
	{
		*new_pos_y = *new_pos_y \
			+ speed * sin(display->player.orientation + M_PI);
		*new_pos_x = *new_pos_x \
			+ speed * cos(display->player.orientation + M_PI);
	}
	return (EXIT_FAILURE);
}

int	move_left(t_display *display, double *new_pos_x, double *new_pos_y)
{
	double	speed;

	speed = display->player.speed;
	if (display->keys[KEY_A])
	{
		*new_pos_x = *new_pos_x \
			- speed * cos(display->player.orientation + (M_PI / 2));
		*new_pos_y = *new_pos_y \
			- speed * sin(display->player.orientation + (M_PI / 2));
	}
	return (EXIT_FAILURE);
}

int	move_right(t_display *display, double *new_pos_x, double *new_pos_y)
{
	double	speed;

	speed = display->player.speed;
	if (display->keys[KEY_D])
	{
		*new_pos_x = *new_pos_x \
			+ speed * cos(display->player.orientation + (M_PI / 2));
		*new_pos_y = *new_pos_y \
			+ speed * sin(display->player.orientation + (M_PI / 2));
	}
	return (EXIT_FAILURE);
}
