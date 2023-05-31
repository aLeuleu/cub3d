/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 15:22:03 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_wall(t_display *display, double pos_x, double pos_y);

static int	diagonals_movements(t_display *display, double speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = display->player.pos.x;
	new_pos_y = display->player.pos.y;
	speed = speed / M_SQRT2;
	if (display->keys[KEY_W] && display->keys[KEY_A])
	{
		new_pos_y -= speed;
		new_pos_x -= speed;
	}
	else if (display->keys[KEY_W] && display->keys[KEY_D])
	{
		new_pos_y -= speed;
		new_pos_x += speed;
	}
	else if (display->keys[KEY_S] && display->keys[KEY_A])
	{
		new_pos_y += speed;
		new_pos_x -= speed;
	}
	else if (display->keys[KEY_S] && display->keys[KEY_D])
	{
		new_pos_y += speed;
		new_pos_x += speed;
	}
	else
		return (EXIT_FAILURE);
	if (check_wall(display, new_pos_x, new_pos_y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	display->player.pos.x = new_pos_x;
	display->player.pos.y = new_pos_y;
	return (EXIT_SUCCESS);
}

int	player_movements(t_display *display)
{
	double speed;
	double new_pos_x;
	double new_pos_y;

	new_pos_x = display->player.pos.x;
	new_pos_y = display->player.pos.y;
	speed = display->player.speed / 10;
	if (display->keys[KEY_Q])
		display->player.orientation -= 0.1;
	else if (display->keys[KEY_E])
		display->player.orientation += 0.1;
	if (diagonals_movements(display, speed) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (display->keys[KEY_W])
		new_pos_y -= speed;
	else if (display->keys[KEY_S])
		new_pos_y += speed;
	else if (display->keys[KEY_A])
		new_pos_x -= speed;
	else if (display->keys[KEY_D])
		new_pos_x += speed;
	else
		return (EXIT_FAILURE);
	if (check_wall(display, new_pos_x, new_pos_y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	display->player.pos.x = new_pos_x;
	display->player.pos.y = new_pos_y;
	return (EXIT_SUCCESS);
}

static int check_wall(t_display *display, double pos_x, double pos_y)
{
	t_p a;

	a.x = (pos_x);
	a.y = (pos_y);
	if (display->map.map[(int)(a.y)][(int)(a.x)] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}