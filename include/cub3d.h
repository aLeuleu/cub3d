/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/25 12:44:31 by lpupier          ###   ########.fr       */
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

// Map structure
typedef struct s_map
{
	int		nb_parameter_set;
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	char	*color_f;
	char	*color_c;
	t_list	*map;
}	t_map;

// Display structure
typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
}	t_display;

// parsing.c
int		parsing(int argc, char **argv);

// check_file_extention.c
int		check_file_extention(char *file);

// get_textures_colors.c
int		get_textures_colors(int fd, t_map *map);
int		is_str_empty(char *line);
int		is_texture_color(char **line_tab, t_map *map);

// get_map.c
int		get_map(int fd, t_map *map);
int		fill_map(char *line, t_map *map);

// events.c
int		quit_window(t_display *display);

// utils.c
void	free_memory(t_map *map);

// errors.c
void	error(char *str);
void	bad_format_line(int idx);

#endif