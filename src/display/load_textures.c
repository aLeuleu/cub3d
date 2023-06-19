/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 14:36:16 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_xpm_file(void *mlx, char *path, t_data *img)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(\
		mlx, \
		path, \
		&img_width, \
		&img_height);
	if (img->img == NULL)
		return (EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}

static void	free_images_no_so(void *mlx, t_map *map)
{
	mlx_destroy_image(mlx, map->texture_no.img);
	mlx_destroy_image(mlx, map->texture_so.img);
}

int	load_textures(void *mlx, t_map *map)
{
	int	status;

	status = EXIT_SUCCESS;
	if (load_xpm_file(mlx, map->path_texture_no, &map->texture_no))
		status = EXIT_FAILURE;
	if (load_xpm_file(mlx, map->path_texture_so, &map->texture_so))
	{
		mlx_destroy_image(mlx, map->texture_no.img);
		status = EXIT_FAILURE;
	}
	if (load_xpm_file(mlx, map->path_texture_we, &map->texture_we))
	{
		free_images_no_so(mlx, map);
		status = EXIT_FAILURE;
	}
	if (load_xpm_file(mlx, map->path_texture_ea, &map->texture_ea))
	{
		free_images_no_so(mlx, map);
		mlx_destroy_image(mlx, map->texture_we.img);
		status = EXIT_FAILURE;
	}
	if (status == EXIT_FAILURE)
		error("An error occurred while loading a texture");
	return (status);
}
