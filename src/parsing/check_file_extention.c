/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:03 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 16:53:57 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief The purpose of the function is to check the extension of the file
 * passed as a parameter to see if it ends by '.cub' or not.
 * 
 * @param file Path to the file representing the map
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	check_file_extention(char *file)
{
	char	**file_tab;
	int		len;

	file_tab = ft_split(file, '.');
	len = ft_len_tab(file_tab);
	if (len < 2)
	{
		error("The file has no extension");
		return (ft_free_tab(file_tab), EXIT_FAILURE);
	}
	if (!ft_strcmp(file_tab[len - 1], "cub"))
		return (ft_free_tab(file_tab), EXIT_SUCCESS);
	error("The expected map extension is '.cub'");
	return (ft_free_tab(file_tab), EXIT_FAILURE);
}
