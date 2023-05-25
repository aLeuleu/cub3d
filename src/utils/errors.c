/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:37:03 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 17:03:53 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Error display function to warn the user of a problem.
 * 
 * @param str Character string to display as an error message.
 */
void	error(char *str)
{
	printf("Error\n -%s\n", str);
}

/**
 * @brief Display function to inform the user of a line
 * in the incorrectly formatted map.
 * 
 * @param idx Line number affected by the formatting error.
 */
void	bad_format_line(int idx)
{
	error("The map is misconfigured, this line was not recognized:");
	printf("  -> Line %d\n", idx);
}
