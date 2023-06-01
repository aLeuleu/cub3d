/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_opening.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:43:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/01 09:51:46 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_minimap_opening(t_display *display)
{
	if (display->keys[KEY_M])
	{
		if (display->display_mode == GAME)
			display->display_mode = MINIMAP;
		else if (display->display_mode == MINIMAP)
			display->display_mode = MAP;
		else
			display->display_mode = GAME;
	}
	return (EXIT_SUCCESS);
}