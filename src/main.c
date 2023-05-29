/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 15:51:56 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Main function of the program calling the execution
 * tasks of the program.
 * 
 * @param argc Number of parameters passed to the execution of the program.
 * @param argv Arguments passed to the execution of the program.
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	main(int argc, char **argv)
{
	t_display	display;

	init_display_struct(&display);
	if (init_map_struct(&display) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (parsing(argc, argv, &display) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_textures(&display) == EXIT_FAILURE)
	{
		error("An error occurred while loading a texture");
		return (EXIT_FAILURE);
	}
	mlx_hook(display.mlx_win, 17, 0, &quit_window, &display);
	display_minimap(&display);
	mlx_put_image_to_window(\
		display.mlx, display.mlx_win, display.img.img, 0, 0);
	mlx_loop(display.mlx);
	return (EXIT_SUCCESS);
}
