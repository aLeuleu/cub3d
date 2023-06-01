/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:43 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 19:25:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frames(t_display *display)
{
	display->offset.x = -display->player.pos.x;
	display->offset.y = -display->player.pos.y;
	ft_memset(display->img.addr, 0, display->height * display->img.line_length);
	ft_memset(display->img_minimap.addr, 0, display->size_minimap * display->size_minimap);
	player_movements(display);
	mlx_put_image_to_window(\
		display->mlx, display->mlx_win, display->img.img, 0, 0);
	if (display->display_mode == MINIMAP)
	{
		display_minimap(display);
		display_coo_player(display);
	}
	return (EXIT_SUCCESS);
}
