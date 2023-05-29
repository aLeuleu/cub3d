/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 18:29:09 by lpupier          ###   ########.fr       */
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
	init_map_struct(&display);
	if (parsing(argc, argv, &display) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	if (load_textures(display.mlx, &display.map) == EXIT_FAILURE)
	{
		error("An error occurred while loading a texture");
		return (quit_window(&display), EXIT_FAILURE);
	}
	display.mlx_win = mlx_new_window(display.mlx, 1920, 1080, "Cub3D - 42");
	mlx_hook(display.mlx_win, 17, 0, &quit_window, &display);
	mlx_loop_hook(display.mlx, render_frames, &display);
	mlx_loop(display.mlx);
	return (EXIT_SUCCESS);
}
