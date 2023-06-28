/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/28 18:45:10 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_wall(t_display *display, double new_pos_x, double new_pos_y)
{
	double	gap;
	double	pos_x;
	double	pos_y;

	gap = 0.3;
	pos_x = display->player.pos.x;
	pos_y = display->player.pos.y;
	if (pos_x < new_pos_x \
	&& display->map.map[(int)(new_pos_y)][(int)(pos_x + gap)] == '1')
		return (EXIT_FAILURE);
	else if (pos_x > new_pos_x \
	&& display->map.map[(int)(new_pos_y)][(int)(pos_x - gap)] == '1')
		return (EXIT_FAILURE);
	if (pos_y < new_pos_y \
	&& display->map.map[(int)(pos_y + gap)][(int)(new_pos_x)] == '1')
		return (EXIT_FAILURE);
	else if (pos_y > new_pos_y \
	&& display->map.map[(int)(pos_y - gap)][(int)(new_pos_x)] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	player_movements(t_display *display)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = display->player.pos.x;
	new_pos_y = display->player.pos.y;
	if (display->player.orientation < 0)
		display->player.orientation = 2 * M_PI;
	else if (display->player.orientation > 2 * M_PI)
		display->player.orientation = 0;
	if (display->keys[KEY_Q] || display->keys[KEY_LEFT])
		display->player.orientation -= 0.04;
	else if (display->keys[KEY_E] || display->keys[KEY_RIGHT])
		display->player.orientation += 0.04;
	move_up(display, &new_pos_x, &new_pos_y);
	move_down(display, &new_pos_x, &new_pos_y);
	move_left(display, &new_pos_x, &new_pos_y);
	move_right(display, &new_pos_x, &new_pos_y);
	if (check_wall(display, new_pos_x, new_pos_y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	display->player.pos.x = new_pos_x;
	display->player.pos.y = new_pos_y;
	return (EXIT_SUCCESS);
}
