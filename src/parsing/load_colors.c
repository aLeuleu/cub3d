/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:44 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 13:36:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_values(char **tab)
{
	int		idx;
	int		number;
	char	*str_trimed;

	if (!tab)
		return (EXIT_FAILURE);
	if (ft_len_tab(tab) != 3)
		return (ft_free_tab(tab), EXIT_FAILURE);
	idx = -1;
	while (++idx < 3)
	{
		str_trimed = ft_strtrim(tab[idx], " \n");
		number = ft_atoi(str_trimed);
		free(str_trimed);
		if (number < 0 || number > 255)
			return (ft_free_tab(tab), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	create_color_value(char **tab)
{
	int	color;

	color = create_trgb(255, ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	return (color);
}

int	load_colors(t_map *map)
{
	char	**tab_color_f;
	char	**tab_color_c;
	
	if (!map->color_f_raw || !map->color_c_raw)
		return (error("The colors provided are not valid"), EXIT_FAILURE);
	tab_color_f = ft_split(map->color_f_raw, ',');
	if (is_valid_values(tab_color_f) == EXIT_FAILURE)
		return (error("Color F is incorrectly formatted"), EXIT_FAILURE);
	tab_color_c = ft_split(map->color_c_raw, ',');
	if (is_valid_values(tab_color_c) == EXIT_FAILURE)
	{
		ft_free_tab(tab_color_f);
		return (error("Color C is incorrectly formatted"), EXIT_FAILURE);
	}
	map->color_f = create_color_value(tab_color_f);
	map->color_c = create_color_value(tab_color_c);
	ft_free_tab(tab_color_f);
	ft_free_tab(tab_color_c);
	return (EXIT_SUCCESS);
}
