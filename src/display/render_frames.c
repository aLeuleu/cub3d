/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:43 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 18:29:27 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frames(t_display *display)
{
	ft_memset(display->img.addr, 0, display->map.height * display->map.width);
	display_minimap(display);
	mlx_put_image_to_window(\
		display->mlx, display->mlx_win, display->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
