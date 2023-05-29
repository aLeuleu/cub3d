/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 14:43:33 by lpupier          ###   ########.fr       */
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

// OS
# ifndef OS_LINUX
#  define OS_LINUX 0
# endif

# ifndef OS_DARWIN
#  define OS_DARWIN 0
# endif

// Map structure
typedef struct s_map
{
	int			nb_parameter_set;
	char		*path_texture_no;
	char		*path_texture_so;
	char		*path_texture_we;
	char		*path_texture_ea;
	void		*texture_no;
	void		*texture_so;
	void		*texture_we;
	void		*texture_ea;
	char		*color_f;
	char		*color_c;
	int			**map;
	int			height;
	int			width;
}	t_map;

// Display structure
typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_display;

// init.c
int		init_map_struct(t_display *display);

// parsing.c
int		parsing(int argc, char **argv, t_display *display);

// check_file_extention.c
int		check_file_extention(char *file);

// get_textures_colors.c
int		get_textures_colors(int fd, t_map *map);
int		is_str_empty(char *line);
int		is_texture_color(char **line_tab, t_map *map);

// get_map.c
int		get_map(int fd, t_map *map);
int		fill_temp_map(char *line, t_list_char **temp_map);
int		fill_map(t_map *map, t_list_char *temp_map);
int		find_big_line(t_list_char *temp_map);

// events.c
int		quit_window(t_display *display);

// utils.c
void	free_memory(t_map *map);

// errors.c
void	error(char *str);
void	bad_format_line(int idx);

// load_textures.c
int		load_textures(t_display *display);
int		load_xpm_file(t_display *display, char *path, void *img);

// free_memory.c
void	free_map(t_map *map);

// display_minimap.c
void	display_minimap(t_display *display);

//draw_tools.c
void	mlx_draw_square(t_display *display, int x, int y, int pos[2], int color);

#endif