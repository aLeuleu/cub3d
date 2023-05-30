/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:37:03 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 14:21:34 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error(char *str)
{
	printf("Error\n -%s\n", str);
}

void	bad_format_line(int idx)
{
	error("The map is misconfigured, this line was not recognized:");
	printf("  -> Line %d\n", idx);
}

void	bad_format_tab(char *text, int line, int column)
{
	printf("Error\n");
	printf(" -The map is misconfigured, %s:\n", text);
	printf("  -> line %d of the map\n", line);
	printf("  -> Column %d\n", column);
}
