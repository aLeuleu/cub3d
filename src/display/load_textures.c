/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 10:33:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	load_xpm_file(void *mlx, char *path, void **img)
{
	char	*new_path;
	int		img_width;
	int		img_height;

	if (path[ft_strlen(path) - 1] == '\n')
		new_path = ft_substr(path, 0, ft_strlen(path) - 1);
	else
		new_path = ft_strdup(path);
	*(img) = mlx_xpm_file_to_image(\
		mlx, \
		new_path, \
		&img_width, \
		&img_height);
	free(new_path);
	if (!img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_textures(void *mlx, t_map *map)
{
	int	status;

	status = EXIT_SUCCESS;
	if (load_xpm_file(mlx, map->path_texture_no, &map->texture_no))
		status = EXIT_FAILURE;
	if (load_xpm_file(mlx, map->path_texture_so, &map->texture_so))
	{
		mlx_destroy_image(mlx, map->texture_no);
		status = EXIT_FAILURE;
	}
	if (load_xpm_file(mlx, map->path_texture_we, &map->texture_we))
	{
		mlx_destroy_image(mlx, map->texture_no);
		mlx_destroy_image(mlx, map->texture_so);
		status = EXIT_FAILURE;
	}
	if (load_xpm_file(mlx, map->path_texture_ea, &map->texture_ea))
	{
		mlx_destroy_image(mlx, map->texture_no);
		mlx_destroy_image(mlx, map->texture_so);
		mlx_destroy_image(mlx, map->texture_we);
		status = EXIT_FAILURE;
	}
	if (status == EXIT_FAILURE)
		error("An error occurred while loading a texture");
	return (status);
}
