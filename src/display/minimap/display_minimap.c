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
//	while (line < display->map->height)
	while (line < 100)
	{
		column = 0;
		while (column < 100)
		{
			pos[0] = column * 10;
			pos[1] = line * 10;
			if (line % 2 == 0 && column % 2 == 0)
				mlx_draw_square(display->mlx, 10, 10, pos, 0xFFFFFF);
			column++;
		}
		line++;
	}
}