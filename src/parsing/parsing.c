/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:04:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/20 17:10:53 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (get_textures_colors(fd, &display->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map(fd, &display->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_player_position(display);
	close(fd);
	return (EXIT_SUCCESS);
}
