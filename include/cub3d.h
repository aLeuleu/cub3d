/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 17:28:58 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

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
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	char	*color_f;
	char	*color_c;
	int		*map;
}	t_map;

// parsing.c
int		parsing(int argc, char **argv);

// check_file_extention.c
int		check_file_extention(char *file);

// get_textures_colors.c
int		get_textures_colors(int fd, t_map *map);
int		is_str_empty(char *line);
int		is_texture_color(char **line_tab, int idx, t_map *map);

// get_map.c
int		get_map(int fd, t_map *map);

// events.c
int		quit_window(t_display *display);

// errors.c
void	error(char *str);
void	bad_format_line(int idx);

#endif