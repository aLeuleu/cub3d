/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/06/19 14:54:22 by lpupier          ###   ########.fr       */
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
#  define KEY_LEFT 254
#  define KEY_RIGHT 255
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
#  define KEY_ESCAPE 53
#  define MOUSE_LEFT 1
#  define MOUSE_MIDDLE 2
#  define MOUSE_RIGHT 3
#  define MOUSE_DOWN 4
#  define MOUSE_UP 5
# endif

# define BLACK			0x000000
# define LIGHT_BLUE		0xBED0FF
# define BLUE			0x0000FF
# define DARK_BLUE		0x0037C9
# define GREY			0x808080
# define LIGHT_GREEN	0x83957d
# define GREEN			0x008000
# define DARK_GREEN		0x396f28
# define PURPLE			0x800080
# define RED			0xFF0000
# define WHITE			0xFFFFFF

# define IMG_SIZE	64

# define TWO_PI	6.28318530717958647692528676655900576

// Point structure
typedef struct s_p {
	double		x;
	double		y;
	int			color;
	bool		collision;
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
	t_data		texture_no;
	t_data		texture_so;
	t_data		texture_we;
	t_data		texture_ea;
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
	double	orientation;
	double	fov;
	double	speed;
	int		score;
	int		life;
	int		max_life;
	int		score_to_win;
}	t_player;

typedef struct s_p_list
{
	t_p		*content;
	t_list	*next;
}	t_p_list;

//enum for orientation
enum e_direction {
	N = 0,
	S = 1,
	E = 2,
	W = 3,
	NE = 4,
	NW = 5,
	SE = 6,
	SW = 7
};

// Display structure
typedef struct s_display
{
	void		*mlx;
	void		*mlx_win;
	int			height;
	int			width;
	int			size_minimap;
	t_p			offset;
	int			*keys;
	int			display_mode;
	double		ray_len;
	t_data		img;
	t_map		map;
	t_player	player;
}	t_display;

// Key events
enum e_key_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// Map events
enum e_map_events {
	GAME,
	MINIMAP,
	MAP
};

// main.c
int			main(int argc, char **argv);

// init.c
int			init_display_struct(t_display *display);
int			init_map_struct(t_map *map);
void		init_player(t_display *display);

// parsing
int			parsing(int argc, char **argv, t_display *display);
int			check_file_extention(char *file);
int			get_textures_colors(int fd, t_map *map);
void		get_player_position(t_display *display);
int			get_map(int fd, t_map *map);
int			map_is_formated(t_map *map);
int			create_trgb(int t, int r, int g, int b);
int			load_colors(t_map *map);

// events
int			quit_window(t_display *display);
int			check_minimap_opening(t_display *display);
void		init_map_image(t_display *display);
int			check_keycode(int keycode, t_display *display);
int			check_keycode_up(int keycode, t_display *display);
int			check_mousecode(int x, int y, t_display *display);
int			player_movements(t_display *display);
int			move_up(t_display *display, double *new_pos_x, \
			double *new_pos_y);
int			move_down(t_display *display, double *new_pos_x, \
			double *new_pos_y);
int			move_left(t_display *display, double *new_pos_x, \
			double *new_pos_y);
int			move_right(t_display *display, double *new_pos_x, \
			double *new_pos_y);

// utils
t_p			init_point(int x, int y);
void		error(char *str);
void		bad_format_line(int idx);
void		bad_format_tab(char *text, int line, int column);
void		free_map(t_map *map);
void		free_images(t_display *display);

// display
int			load_textures(void *mlx, t_map *map);
int			render_frames(t_display *display);

// minimap
void		display_minimap(t_display *display);
void		my_mlx_pixel_put_minimap(t_display *display, int x, int y, \
			int color);
void		mlx_draw_square_minimap(\
			t_display *display, int side_len, t_p pos, int color);
void		mlx_draw_circle_minimap(\
			t_display *display, int radius, t_p pos, int color);
void		mlx_draw_circle_player(t_display *display, int radius, \
			double orientation, t_p pos);
double		offset_minimap(t_display *display, double point, double offset);
int			draw_frame_minimap(t_display *display);

// textures
bool		display_textures(t_display *display, t_p w_up, t_p w_down, \
			t_p p_col);

// draw_tools
void		my_mlx_pixel_put(t_display *display, int x, int y, int color);
size_t		ft_max(size_t a, size_t b);
void		mlx_draw_line(t_display *display, t_p a, t_p b, int color);
void		mlx_draw_vertical_lines(t_display *display, \
			t_p up, t_p down, int color);

// player behavior
void		init_player(t_display *display);

//display game
void		display_game(t_display *display);
double		floor2(double n);
t_p			closest_point(t_p start, t_p p1, t_p p2);

//math formulas
void		north_formula(t_p *point, t_p *tmp);
void		south_formula(t_p *point, t_p *tmp);
void		east_formula(t_p *point, t_p *tmp);
void		west_formula(t_p *point, t_p *tmp);

//raycasting
void		compute_points_untill_collision(t_p *ix, t_p *iy, \
			t_display *display, double angle);
void		compute_cardinal_collision(t_p *point, t_display *display, \
			int orientation);
void		compute_y_points_untill_collision(t_p *point, \
const double *tan_angle, t_display *display, int orientation);
void		compute_x_points_untill_collision(t_p *point, \
const double *tan_angle, t_display *display, int orientation);
bool		check_collision(t_display *display, t_p p, int orientation);
void		angle_routine(double angle, double *tan_angle, int orientation);
void		adjust_angle(double *angle);
void		get_orientation(int *orientation, double angle);
bool		orientation_is_cardinal(int orientation);
#endif