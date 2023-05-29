/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by alevra            #+#    #+#             */
/*   Updated: 2023/05/26 15:28:29 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_minimap(t_display *display)
{
	int	line;
	int	column;
	int pos[2] = {0, 0};

	line = 0;
	while (line < display->map->height)
	{
		column = 0;
		while (column < display->map->width)
		{
			pos[0] = column * 30;
			pos[1] = line * 30;
			if (display->map->map[line][column] == '1')
				mlx_draw_square(display->mlx, 30, 30, pos, 0xFFFFFF);
			column++;
		}
		line++;
	}
}