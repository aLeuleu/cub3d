/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:56:09 by alevra            #+#    #+#             */
/*   Updated: 2023/05/31 15:22:03 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_ray(t_display *display)
{
	if (display->keys[KEY_UP])
	{
		display->debug.ray += 5;
		if (display->debug.ray > display->width)
			display->debug.ray = 0;
	}
	if (display->keys[KEY_DOWN])
	{
		display->debug.ray -= 5;
		if (display->debug.ray < 0)
			display->debug.ray = display->width;
	}
}