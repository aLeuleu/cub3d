/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 14:12:09 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_wall(t_display *display, double pos_x, double pos_y)
{
	t_p	a;

	if (display->player.closest_wall < 0.3)
		return (EXIT_FAILURE);
	a.x = (pos_x);
	a.y = (pos_y);
	if (a.x > display->player.pos.x)
		a.x += 0.3;
	else
		a.x -= 0.3;
	if (a.y > display->player.pos.y)
		a.y += 0.3;
	else
		a.y -= 0.3;
	if ((int)(a.y) >= display->map.height || (int)(a.x) >= display->map.width \
	|| (int)(a.y) <= 0 || (int)(a.x) <= 0)
		return (EXIT_FAILURE);
	if (display->map.map[(int)(a.y)][(int)(a.x)] == '1' \
	|| display->map.map[(int)(a.y)][(int)(a.x)] == ' ')
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
