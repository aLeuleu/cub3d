/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/20 17:29:40 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	load_xpm_file(void *mlx, char *path, t_data *img)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(\
		mlx, \
		path, \
		&img_width, \
		&img_height);
	if (img->img == NULL)
		return (false);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	return (true);
}

static void	free_image(void *mlx, void **img_ptr)
{
	mlx_destroy_image(mlx, *img_ptr);
	*img_ptr = NULL;
}

static int	loading(void *mlx, t_map *map)
{
	if (load_xpm_file(mlx, map->path_texture_no, &map->texture_no) == false)
		return (EXIT_FAILURE);
	if (load_xpm_file(mlx, map->path_texture_so, &map->texture_so) == false)
	{
		free_image(mlx, &map->texture_no.img);
		return (EXIT_FAILURE);
	}
	if (load_xpm_file(mlx, map->path_texture_we, &map->texture_we) == false)
	{
		free_image(mlx, &map->texture_no.img);
		free_image(mlx, &map->texture_so.img);
		return (EXIT_FAILURE);
	}
	if (load_xpm_file(mlx, map->path_texture_ea, &map->texture_ea) == false)
	{
		free_image(mlx, &map->texture_no.img);
		free_image(mlx, &map->texture_so.img);
		free_image(mlx, &map->texture_we.img);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	load_textures(void *mlx, t_map *map)
{
	if (loading(mlx, map) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	error("An error occurred while loading a texture");
	return (EXIT_FAILURE);
}
