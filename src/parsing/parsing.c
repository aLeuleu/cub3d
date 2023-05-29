/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:04:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 14:13:40 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Map file parsing function with recognition
 * of textures, colors and the game map.
 * 
 * @param argc Number of parameters passed to the execution of the program.
 * @param argv Arguments passed to the execution of the program.
 * @param display General structure for screen display (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	parsing(int argc, char **argv, t_display *display)
{
	char	*file;
	int		fd;

	if (argc != 2)
	{
		error("Please give the path of a map");
		return (EXIT_FAILURE);
	}
	file = argv[1];
	if (check_file_extention(file) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error("The file does not exist or cannot be opened");
		return (EXIT_FAILURE);
	}
	if (get_textures_colors(fd, display->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map(fd, display->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
