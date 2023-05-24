/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:49 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 12:50:07 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// Minilibx
# include "mlx.h"

// Libft
# include "../libft/includes/libft.h"

// Map structure
typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
}	t_map;

// events.c
int	quit_window(t_map *map);

#endif