/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 14:14:59 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// Minilibx & libft
# include "mlx.h"
# include "../libft/includes/libft.h"

// Display structure
typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
}	t_display;

// Map structure
typedef struct s_map
{
}	t_map;

// parsing.c
int		parsing(int argc, char **argv);
int		check_file_extention(char *file);

// events.c
int		quit_window(t_display *display);

#endif