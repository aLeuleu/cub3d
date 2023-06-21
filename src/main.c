/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:29 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/21 17:04:25 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_hooks(t_display *display);

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
	mlx_hooks(&display);
	return (EXIT_SUCCESS);
}

static void	mlx_hooks(t_display *display)
{
	mlx_hook((*display).mlx_win, 2, 1L << 0, check_keycode, display);
	mlx_hook((*display).mlx_win, 3, 1L << 1, check_keycode_up, display);
	if (OS_LINUX)
		mlx_hook((*display).mlx_win, 6, 1L << 6, check_mousecode, display);
	mlx_hook((*display).mlx_win, 17, 0, quit_window, display);
	mlx_loop_hook((*display).mlx, render_frames, display);
	if (OS_LINUX)
		mlx_mouse_hide((*display).mlx, (*display).mlx_win);
	mlx_loop((*display).mlx);
}
