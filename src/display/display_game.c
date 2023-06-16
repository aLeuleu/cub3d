/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/01 16:55:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool find_collision(t_display *display, t_p *start, t_p *p_collision, double angle);
static bool check_collision(t_display *display, t_p p, int orientation);
		t_p 	farest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	closest_point(t_p start, t_p p1, t_p p2); // a mettre dans un bibli
t_p 	add_points(t_p p1, t_p p2); // a mettre dans un bibli
char *ftoa(double n); //only debug
static double floor2(double n);

void angle_routine(t_display *display, double angle, double *tan_angle);

void	display_game(t_display *display)
{
	t_p pos;
	double lin_len;
	int wall_color_NS = 0xE9806E; //red
	int wall_color_EW = 0x650D1B; //giant orange
	int wall_color;
	t_p wall_up;
	t_p wall_down;
	double ray_len;
	double wall_height;
	int zoom = display->map.zoom;
	pos.x = display->player.pos.x * zoom;
	pos.y = display->player.pos.y * zoom;
	int count = 0;
	double i;
	t_p start_pos;

	t_p p_collision;
	double angle;
	const double half_height = (double)display->height / 2;
	const double one_on_width =  2/((double)display->width);


	i = -1;
	while ( i <= 1)
	{
		if (display->debug.ray == count)
			display->debug.ray = count;
		start_pos = display->player.pos;
		angle = display->player.orientation + (M_PI * i/ 6);
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		p_collision = start_pos;
		find_collision(display, &start_pos, &p_collision, angle);
		ray_len = sqrt(pow(p_collision.x - display->player.pos.x, 2) + pow(p_collision.y - display->player.pos.y, 2));

		lin_len = ray_len * cos(angle - display->player.orientation);
		wall_height = (double)display->height/lin_len;
		if (ray_len < 0.1)
			ray_len = 0.1;
		if (wall_height > display->height)
			wall_height = display->height;
		wall_up.x = count;
		wall_up.y = half_height - (double)wall_height / 2;
		wall_down.x = wall_up.x;
		wall_down.y = half_height + (double)wall_height / 2;
		if (p_collision.x == (int) p_collision.x)
			wall_color = wall_color_EW;
		else
			wall_color = wall_color_NS;
		if (display->debug.ray == count)
		{
			t_p debug_up;
			t_p debug_down;
			display->debug.ray_len = ray_len;
			display->debug.collision = p_collision;
			display->debug.ix = display->debug.ix_tmp;
			display->debug.iy = display->debug.iy_tmp;
			display->debug.new_angle = display->debug.new_angle_tmp;
			display->debug.angle = angle;
			display->debug.tan_angle = display->debug.tan_angle_tmp;
			debug_up.x = count;
			debug_up.y = 0;
			debug_down.x = count;
			debug_down.y = half_height;
			mlx_draw_vertical_lines(display, debug_up, debug_down, 0xFF0000);
		}
		mlx_draw_vertical_lines(display, wall_up, wall_down, wall_color);
		i += one_on_width;
		count++;
	}
}

t_p 	add_points(t_p p1, t_p p2)
{
	t_p p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return (p3);
}

t_p 	closest_point(t_p start, t_p p1, t_p p2)
{
	t_p closest;

	double d1 = sqrt(pow(p1.x - start.x, 2) + pow(p1.y - start.y, 2));
	double d2 = sqrt(pow(p2.x - start.x, 2) + pow(p2.y - start.y, 2));

	if (d1 < d2)
	{closest = p1; }
	else
	{closest = p2;}
	return (closest);
}

t_p 	farest_point(t_p start, t_p p1, t_p p2)
{
	t_p farest;

	double d1 = sqrt(pow(p1.x - start.x, 2) + pow(p1.y - start.y, 2));
	double d2 = sqrt(pow(p2.x - start.x, 2) + pow(p2.y - start.y, 2));

	if (d1 > d2)
		farest = p1;
	else
		farest = p2;
	return (farest);
}

void angle_routine(t_display *display, double angle, double *tan_angle)
{
	if (angle < 0 || angle > M_PI / 2)
 		printf("ERROR\n");
	display->debug.new_angle_tmp = angle;
	*tan_angle = tan(angle);
	if (*tan_angle < 0)
		*tan_angle *= -1;
	display->debug.tan_angle_tmp = *tan_angle;
}

bool check_collision(t_display *display, t_p p, int orientation)
{
	if ((orientation == NW || orientation == SW)  && (int)p.x == p.x) // WEST
		p.x -= 1;
	if ((orientation == NE || orientation == NW)  && (int)p.y == p.y) // NORTH
		p.y -= 1;
	if (p.x < 0 || p.x >= display->map.width || p.y < 0 || p.y >= display->map.height)
		return (true);
	if (display->map.map[(int)(p.y)][(int)(p.x)] == '1')
		return (true);
	return (false);
}

bool	find_collision(t_display *display, t_p *start, t_p *p_collision, double angle)
{
	t_p ix;
	t_p iy;
	t_p tmp;
	bool collisionx;
	bool collisiony;
	double tan_angle;
	collisionx = false;
	collisiony = false;
	const double two_pi = 2 * M_PI;
	ix.x = 0;
	ix.y = 0;
	iy.x = 0;
	iy.y = 0;
	if (angle > 0 && angle < M_PI_2) // SE
	{
		display->debug.orientation = SE;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = ((int)(tmp.x)) + 1;
			ix.y = tmp.y + (ix.x - tmp.x) * tan_angle;
			collisionx = check_collision(display, ix, SE);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = ((int)(tmp.y)) + 1;
			iy.x = tmp.x + (iy.y - tmp.y) / tan_angle;
			collisiony = check_collision(display, iy, SE);
			tmp = iy;
		}
	}
	else if (angle > M_PI_2 && angle < M_PI) // SW
	{
		display->debug.orientation = SW;
		angle = M_PI - angle;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (floor2(tmp.x));
			ix.y = tmp.y + (tmp.x - ix.x) * tan_angle;
			collisionx = check_collision(display, ix, SW);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = ((int)(tmp.y)) + 1;
			iy.x = tmp.x - (iy.y - tmp.y) / tan_angle;
			collisiony = check_collision(display, iy, SW);
			tmp = iy;
		}
	}
	else if (angle > M_PI && angle < 3 * M_PI_2) // NW
	{
		display->debug.orientation = NW;
		angle = angle - M_PI;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (floor2(tmp.x));
			ix.y = tmp.y - (tmp.x - ix.x) * tan_angle;
			collisionx = check_collision(display, ix, NW);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = (floor2(tmp.y));
			iy.x = tmp.x - (tmp.y - iy.y) / tan_angle;
			collisiony = check_collision(display, iy, NW);
			tmp = iy;
		}
	}
	else if (angle > 3 * M_PI_2 && angle < two_pi) // NE
	{
		display->debug.orientation = NE;
		angle = two_pi - angle;
		angle_routine(display, angle, &tan_angle);

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (int)(tmp.x) + 1;
			ix.y = tmp.y - (ix.x - tmp.x) * tan_angle;
			collisionx = check_collision(display, ix, NE);
			tmp = ix;
		}
		tmp = *start;
		while (!collisiony)
		{
			iy.y = floor2(tmp.y);
			iy.x = tmp.x + (tmp.y - iy.y) / tan_angle;
			collisiony = check_collision(display, iy, NE);
			tmp = iy;
		}

	}
	else if (angle == 0 || angle == two_pi) //E
	{
		display->debug.orientation = E;
		display->debug.new_angle_tmp = angle;

		tmp = *start;
		while (!collisionx)
		{
			ix.x = (int)(tmp.x) + 1;
			ix.y = tmp.y;
			collisionx = check_collision(display, ix, E);
			tmp = ix;
		}
		iy = ix;
	}
	else if (angle == M_PI_2) //S
	{
		display->debug.orientation = S;
		display->debug.new_angle_tmp = angle;

		ix.x = 0;
		ix.y = 0;
		tmp = *start;
		while (!collisiony)
		{
			iy.x = tmp.x;
			iy.y = (int)(tmp.y) + 1;
			collisiony = check_collision(display, iy, S);
			tmp = iy;
		}
		ix = iy;
	}
	else if (angle == M_PI) //W
	{
		display->debug.orientation = W;
		display->debug.new_angle_tmp = angle;

		ix.x = (floor2(start->x) );
		ix.y = start->y;

		iy.x = 0;
		iy.y = 0;
		tmp = ix;
		collisionx = check_collision(display, ix, W);
		while (!collisionx)
		{
			ix.x = ((int) (tmp.x) - 1);
			ix.y = tmp.y;
			collisionx = check_collision(display, ix, W);
			tmp = ix;
		}
		iy = ix;
	}
	else if (angle == 3 * M_PI_2) //N
	{
		display->debug.orientation = N;
		display->debug.new_angle_tmp = angle;

		iy.x = start->x;
		iy.y = floor2(start->y);
		tmp = iy;
		while (!collisiony)
		{
			iy.x = tmp.x;
			iy.y = (int)(tmp.y) - 1;
			collisiony = check_collision(display, iy, N);
			tmp = iy;
		}
		ix = iy;
	}
	else
	{
		ix.x = 0;
		ix.y = 0;
		iy.x = 0;
		iy.y = 0;
	}
	display->debug.ix_tmp = ix;
	display->debug.iy_tmp = iy;
	display->debug.collision_type = 0;
	ix.collision = true;
	iy.collision = true;
	if (ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height)
	{
		ix.collision = false;
//		if (display->map.map[(int)(ix.y)][(int)(ix.x)] == '1')
//			ix.collision = true;
	}
	if (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height)
	{
		iy.collision = false; //tester ca
//		if (display->map.map[(int)(iy.y)][(int)(iy.x)] == '1')
//			iy.collision = true;
	}
	if (ix.collision && iy.collision)
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	if (ix.collision)
	{
		*p_collision = ix;
		return (true);
	}
	if (iy.collision)
	{
		*p_collision = iy;
		return (true);
	}
	display->debug.collision_type = 1;
	if ((ix.x < 0 || ix.x >= display->map.width || ix.y < 0 || ix.y >= display->map.height) \
		&& (iy.x < 0 || iy.x >= display->map.width || iy.y < 0 || iy.y >= display->map.height))
	{
		*p_collision = closest_point(*start, ix, iy);
		return (true);
	}
	return (false);
}

int display_debug(t_display *display) //debug, do not send this to vogsphere
{
	char *coord_x_txt = ft_strjoin("x : ", ftoa(display->player.pos.x));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap, WHITE, coord_x_txt);

	free(coord_x_txt);

	char *coord_y_txt = ft_strjoin("y : ", ftoa(display->player.pos.y));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 20, WHITE, coord_y_txt);
	free(coord_y_txt);

	char *ray_len_txt = ft_strjoin("ray len : ",ftoa(display->debug.ray_len) );

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 40, WHITE, ray_len_txt);
	free(ray_len_txt);

	char *lin_len_txt = ft_strjoin("lin len : ", ftoa(display->debug.lin_len));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 60, WHITE, lin_len_txt);
	free(lin_len_txt);

	char *angle_txt = ft_strjoin("angle : ", ftoa(display->debug.angle));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 80, WHITE, angle_txt);
	free(angle_txt);

	char *collision_x_txt = ft_strjoin("collision x : ", ftoa(display->debug.collision.x));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 100, WHITE, collision_x_txt);
	free(collision_x_txt);

	char *collision_y_txt = ft_strjoin("collision y : ", ftoa(display->debug.collision.y));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 120, WHITE, collision_y_txt);
	free(collision_y_txt);

	char *collision_type_txt;
	if (display->debug.collision_type == 0)
		collision_type_txt = ft_strdup("collision type : WALL");
	else
		collision_type_txt = ft_strdup("collision type : OUT OF MAP");

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 140, WHITE, collision_type_txt);
	free(collision_type_txt);

	char *orientation_txt;

	if (display->debug.orientation == SE)
		orientation_txt = ft_strdup("orientation : SE");
	else if (display->debug.orientation == SW)
		orientation_txt = ft_strdup("orientation : SW");
	else if (display->debug.orientation == NW)
		orientation_txt = ft_strdup("orientation : NW");
	else if (display->debug.orientation == NE)
		orientation_txt = ft_strdup("orientation : NE");
	else if (display->debug.orientation == E)
		orientation_txt = ft_strdup("orientation : E");
	else if (display->debug.orientation == S)
		orientation_txt = ft_strdup("orientation : S");
	else if (display->debug.orientation == W)
		orientation_txt = ft_strdup("orientation : W");
	else if (display->debug.orientation == N)
		orientation_txt = ft_strdup("orientation : N");
	else
		orientation_txt = ft_strdup("orientation : 0");

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 160, WHITE, orientation_txt);
	free(orientation_txt);

	//i1 and i2 calculus
	t_p ix = display->debug.ix;
	t_p iy = display->debug.iy;
	char *i1_txt = ft_strjoin("ix : ", ftoa(ix.x));
	char *i1_txt2 = ft_strjoin(i1_txt, ", ");
	free(i1_txt);
	i1_txt = ft_strjoin(i1_txt2, ftoa(ix.y));
	free(i1_txt2);
	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 180, WHITE, i1_txt);
	free(i1_txt);

	char *i2_txt = ft_strjoin("iy : ", ftoa(iy.x));
	char *i2_txt2 = ft_strjoin(i2_txt, ", ");
	free(i2_txt);
	i2_txt = ft_strjoin(i2_txt2, ftoa(iy.y));
	free(i2_txt2);
	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 200, WHITE, i2_txt);
	free(i2_txt);

	char *new_angle = ft_strjoin("new angle : ", ftoa(display->debug.new_angle));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 220, WHITE, new_angle);
	free(new_angle);

	char *tan_angle = ft_strjoin("tan angle : ", ftoa(display->debug.tan_angle));

	mlx_string_put(display->mlx, display->mlx_win, \
	5, display->size_minimap + 240, WHITE, tan_angle);
	free(tan_angle);

	return (EXIT_SUCCESS);
}

//debug
char 	*ftoa(double n)
{
	char *str;
	char *tmp;
	char *tmp2;
	int i;

	i = 0;
	str = ft_itoa((int)n);
	tmp = ft_strjoin(str, ".");
	free(str);
	n -= (int)n;
	while (i < 1)
	{
		n *= 10;
		str = ft_itoa((int)n);
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		tmp = tmp2;
		n -= (int)n;
		i++;
	}
	return (tmp);
}

static double floor2(double n)
{
	double	res;

	res = (int) n;
	if (n == (int) n)
		res -= 1;
	return (res);
}
