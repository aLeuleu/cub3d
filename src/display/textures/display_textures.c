/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:27:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 14:14:08 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_data	*get_right_texture(t_display *display, t_p p_col, \
					double tmp, int *x_color)
{
	*x_color = (tmp - (int)tmp) * IMG_SIZE;
	if (p_col.x == (int)p_col.x)
	{
		if (display->player.pos.x > p_col.x)
		{
			*x_color = (1 - (tmp - (int)tmp)) * IMG_SIZE;
			return (&display->map.texture_we);
		}
		else
			return (&display->map.texture_ea);
	}
	else
	{
		if (display->player.pos.y > p_col.y)
			return (&display->map.texture_no);
		else
		{
			*x_color = (1 - (tmp - (int)tmp)) * IMG_SIZE;
			return (&display->map.texture_so);
		}
	}
}

static unsigned int	ft_get_color(t_data *data, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	dst = data->addr + (y % IMG_SIZE * data->line_length + x % IMG_SIZE * \
		(data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

bool	display_textures(t_display *display, t_p w_up, t_p w_down, t_p p_col)
{
	int				i;
	unsigned int	color;
	int				x_color;
	int				y_color;
	double			tmp;

	i = 0;
	while (i < w_down.y - w_up.y)
	{
		if (w_up.y + i < 0 || w_up.y + i >= display->height)
		{
			i++;
			continue ;
		}
		if (p_col.x == (int)p_col.x)
			tmp = p_col.y;
		else
			tmp = p_col.x;
		y_color = i * IMG_SIZE / (w_down.y - w_up.y);
		color = ft_get_color(\
			get_right_texture(display, p_col, tmp, &x_color), x_color, y_color);
		my_mlx_pixel_put(display, w_up.x, w_up.y + i, color);
		i++;
	}
	return (true);
}
