/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/26 16:06:23 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Function used to load all the textures of the game
 * in order to reuse them.
 * 
 * @param display General structure for screen display (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	load_textures(t_display *display)
{
	t_map	*map;

	map = display->map;
	if (load_xpm_file(display, map->path_texture_no, map->texture_no))
		return (EXIT_FAILURE);
	if (load_xpm_file(display, map->path_texture_so, map->texture_so))
	{
		mlx_destroy_image(display->mlx, map->texture_no);
		return (EXIT_FAILURE);
	}
	if (load_xpm_file(display, map->path_texture_we, map->texture_we))
	{
		mlx_destroy_image(display->mlx, map->texture_no);
		mlx_destroy_image(display->mlx, map->texture_so);
		return (EXIT_FAILURE);
	}
	if (load_xpm_file(display, map->path_texture_ea, map->texture_ea))
	{
		mlx_destroy_image(display->mlx, map->texture_no);
		mlx_destroy_image(display->mlx, map->texture_so);
		mlx_destroy_image(display->mlx, map->texture_we);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Function to load an .xml file into an image
 * capable of being displayed on the screen.
 * 
 * @param display General structure for screen display (see include/cub3d.h)
 * @param path Path to desired texture
 * @param img Pointer to the memory space capable of hosting the loaded image
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	load_xpm_file(t_display *display, char *path, void *img)
{
	char	*new_path;
	int		img_width;
	int		img_height;

	if (path[ft_strlen(path) - 1] == '\n')
		new_path = ft_substr(path, 0, ft_strlen(path) - 1);
	else
		new_path = ft_strdup(path);
	img = mlx_xpm_file_to_image(\
		display->mlx, \
		new_path, \
		&img_width, \
		&img_height);
	free(new_path);
	if (!img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}