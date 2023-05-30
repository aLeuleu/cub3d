/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 11:40:51 by lpupier          ###   ########.fr       */
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

	// A deplacer tu connais
	ft_memset(display.keys, 0, 70000);

	init_display_struct(&display);
	init_map_struct(&display);
	if (parsing(argc, argv, &display) == EXIT_FAILURE)
		return (quit_window(&display), EXIT_FAILURE);
	if (load_textures(display.mlx, &display.map) == EXIT_FAILURE)
	{
		error("An error occurred while loading a texture");
		return (quit_window(&display), EXIT_FAILURE);
	}
//	init_player(&display);
	display.mlx_win = mlx_new_window(\
		display.mlx, display.width, display.height, "Cub3D - 42");
	mlx_hook(display.mlx_win, 17, 0, &quit_window, &display);
	mlx_hook(display.mlx_win, ON_KEYDOWN, 1L<<0, &check_keycode, &display);
	mlx_hook(display.mlx_win, ON_KEYUP, 1L<<1, &check_keycode_up, &display);
	mlx_mouse_hook(display.mlx_win, &check_mousecode, &display);
	mlx_loop_hook(display.mlx, render_frames, &display);
	mlx_loop(display.mlx);
	return (EXIT_SUCCESS);
}

void	init_player(t_display *display)
{
	display->player.fov = 60;
}