/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 18:26:10 by lpupier          ###   ########.fr       */
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

typedef struct s_p {
	int		x;
	int		y;
	int		color;
}				t_p;

// Data image structure
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
	char		**map;
	int			height;
	int			width;
}	t_map;

// Player structure
typedef struct s_player
{
	int 	pos_x;
	int 	pos_y;
	double 	orientation;
	int 	speed;
	int 	score;
	int 	life;
	int 	max_life;
	int 	score_to_win;
}	t_player;

// Display structure
typedef struct s_display
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_map		map;
	t_player	player;
}	t_display;

// init.c
int		init_display_struct(t_display *display);
int		init_map_struct(t_display *display);

// parsing.c
int		parsing(int argc, char **argv, t_display *display);

// check_file_extention.c
int		check_file_extention(char *file);

// get_textures_colors.c
int		get_textures_colors(int fd, t_map *map);

// get_player_position.c
void	get_player_position(t_player *player, t_map *map);

// get_map.c
int		get_map(int fd, t_map *map);

// events.c
int		quit_window(t_display *display);

// errors.c
void	error(char *str);
void	bad_format_line(int idx);

// load_textures.c
int		load_textures(void *mlx, t_map *map);

// render_frames.c
int		render_frames(t_display *display);

// free_memory.c
void	free_map(t_map *map);
void	free_images(t_display *display);

// display_minimap.c
void	display_minimap(t_display *display);

//draw_tools
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_draw_square(t_display *display, int side_len, int pos[2], int color);
void	mlx_draw_circle(t_display *display, int side_len, int pos[2], int color);
void	mlx_draw_circle_oriented(t_display *display, int radius, double angle, int color, int pos[2]);
void	mlx_draw_line(t_display *display, t_p a, t_p b, int color);

#endif