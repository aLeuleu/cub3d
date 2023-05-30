/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 11:44:51 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_movements(t_display *display)
{
	if (display->keys[KEY_LEFT])
		display->player.orientation -= 1;
	else if (display->keys[KEY_RIGHT])
		display->player.orientation += 1;
	if (display->keys[KEY_W])
		display->player.pos_y -= 1;
	else if (display->keys[KEY_S])
		display->player.pos_y += 1;
	else if (display->keys[KEY_A])
		display->player.pos_x -= 1;
	else if (display->keys[KEY_D])
		display->player.pos_x += 1;
	return (EXIT_SUCCESS);
}
