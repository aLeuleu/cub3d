/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 15:35:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	diagonals_movements(t_display *display, double speed)
{
	speed = speed / M_SQRT2;
	if (display->keys[KEY_W] && display->keys[KEY_A])
	{
		display->player.pos.y -= speed;
		display->player.pos.x -= speed;
	}
	else if (display->keys[KEY_W] && display->keys[KEY_D])
	{
		display->player.pos.y -= speed;
		display->player.pos.x += speed;
	}
	else if (display->keys[KEY_S] && display->keys[KEY_A])
	{
		display->player.pos.y += speed;
		display->player.pos.x -= speed;
	}
	else if (display->keys[KEY_S] && display->keys[KEY_D])
	{
		display->player.pos.y += speed;
		display->player.pos.x += speed;
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	player_movements(t_display *display)
{
	double speed;

	speed = display->player.speed / 10;
	if (display->keys[KEY_LEFT])
		display->player.orientation -= 0.1;
	else if (display->keys[KEY_RIGHT])
		display->player.orientation += 0.1;
	if (diagonals_movements(display, speed) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (display->keys[KEY_W])
		display->player.pos.y -= speed;
	else if (display->keys[KEY_S])
		display->player.pos.y += speed;
	else if (display->keys[KEY_A])
		display->player.pos.x -= speed;
	else if (display->keys[KEY_D])
		display->player.pos.x += speed;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
