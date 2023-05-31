/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 15:21:48 by lpupier          ###   ########.fr       */
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
# include <stdbool.h>

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

// Linux keycode
# if OS_LINUX == 1
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_E 101
#  define KEY_R 114
#  define KEY_T 116
#  define KEY_Y 121
#  define KEY_U 117
#  define KEY_I 105
#  define KEY_O 111
#  define KEY_P 112
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104
#  define KEY_J 106
#  define KEY_K 107
#  define KEY_L 108
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_C 99
#  define KEY_V 118
#  define KEY_B 98
#  define KEY_N 110
#  define KEY_M 109
#  define KEY_0 48
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57
#  define KEY_SPACE 32
#  define KEY_ESCAPE 65307
#  define MOUSE_LEFT 1
#  define MOUSE_MIDDLE 2
#  define MOUSE_RIGHT 3
#  define MOUSE_DOWN 4
#  define MOUSE_UP 5
# endif

//Darwin keycode
# if OS_DARWIN == 1
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
#  define KEY_R 15
#  define KEY_T 17
#  define KEY_Y 16
#  define KEY_U 32
#  define KEY_I 34
#  define KEY_O 31
#  define KEY_P 35
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_C 8
#  define KEY_V 9
#  define KEY_B 11
#  define KEY_N 45
#  define KEY_M 46
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define KEY_6 22
#  define KEY_7 26
#  define KEY_8 28
#  define KEY_9 25
#  define KEY_0 29
#  define KEY_SPACE 49
#  define KEY_ENTER 36
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define MOUSE_LEFT 1
#  define MOUSE_MIDDLE 2
#  define MOUSE_RIGHT 3
#  define MOUSE_DOWN 4
#  define MOUSE_UP 5
# endif

# define GAME 0
# define MINIMAP 1

// Point structure
typedef struct s_p {
	double		x;
	double		y;
	int			color;
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
	char		*color_f_raw;
	char		*color_c_raw;
	int			color_f;
	int			color_c;
	char		**map;
	int			height;
	int			width;
	int			zoom;
}	t_map;

// Player structure
typedef struct s_player
{
	t_p		pos;
	double 	orientation;
	double	fov;
	double 	speed;
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
	int			height;
	int			width;
	int			*keys;
	int			display_mode;
	t_data		img;
	t_map		map;
	t_player	player;
}	t_display;

// Key events
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// main.c
int		main(int argc, char **argv);

// init.c
int		init_display_struct(t_display *display);
int		init_map_struct(t_map *map);
void	init_player(t_display *display);

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

// map_format.c
int		map_is_formated(t_map *map);

// load_colors.c
int 	load_colors(t_map *map);

// events.c
int		quit_window(t_display *display);

// minimap_opening.c
int		check_minimap_opening(t_display *display);

// key_gestion.c
int		check_keycode(int keycode, t_display *display);
int		check_keycode_up(int keycode, t_display *display);
int		check_mousecode(int moutsecode, int x, int y, t_display *display);

// player_movements.c
int		player_movements(t_display *display);

// errors.c
void	error(char *str);
void	bad_format_line(int idx);
void	bad_format_tab(char *text, int line, int column);

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
void	my_mlx_pixel_put(t_display *display, int x, int y, int color);
void	mlx_draw_square(t_display *display, int side_len, int pos[2], int color);
void	mlx_draw_circle(t_display *display, int radius, t_p pos, int color);
void	mlx_draw_circle_oriented(t_display *display, int radius, double orientation, int color, t_p pos);
void	mlx_draw_line(t_display *display, t_p a, t_p b, int color);

//	player behavior
void	init_player(t_display *display);
void	draw_player(t_display *display, int zoom);
void	mlx_draw_fov(t_display *display, int zoom);
#endif