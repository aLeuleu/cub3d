/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 15:10:20 by lpupier          ###   ########.fr       */
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

	if (init_display_struct(&display) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_map_struct(&display.map);
	init_player(&display);
	if (parsing(argc, argv, &display) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	if (map_is_formated(&display.map) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	if (load_colors(&display.map) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	if (load_textures(display.mlx, &display.map) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	display.mlx_win = mlx_new_window(\
		display.mlx, display.width, display.height, "Cub3D - 42");
	mlx_hook(display.mlx_win, 2, 1L << 0, check_keycode, &display);
	mlx_hook(display.mlx_win, 3, 1L << 1, check_keycode_up, &display);
	mlx_hook(display.mlx_win, 6, 1L << 6, check_mousecode, &display);
	mlx_hook(display.mlx_win, 17, 0, quit_window, &display);
	//debug
	display.player.orientation = 6.2831853071795862;
	display.player.pos.x = 3.1;
	display.player.pos.y = 1.8;
	display.debug.ray = 0;
	//debug
	mlx_loop_hook(display.mlx, render_frames, &display);
	mlx_loop(display.mlx);
	return (EXIT_SUCCESS);
}
