/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_formulas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:03:13 by alevra            #+#    #+#             */
/*   Updated: 2023/06/19 14:57:39 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void west_formula(t_p *point, t_p *tmp)
{
	point->x = ((int) ((*tmp).x) - 1);
	point->y = (*tmp).y;
}

void east_formula(t_p *point, t_p *tmp)
{
	point->x = (int)((*tmp).x) + 1;
	point->y = (*tmp).y;
}

void south_formula(t_p *point, t_p *tmp)
{
	point->x = (*tmp).x;
	point->y = (int)((*tmp).y) + 1;
}

void north_formula(t_p *point, t_p *tmp)
{
	point->x = (*tmp).x;
	point->y = (int)((*tmp).y) - 1;
}