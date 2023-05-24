/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:04:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 14:23:43 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parsing(int argc, char **argv)
{
	char	*file;

	if (argc != 2)
	{
		printf("Error\n -Please give the path of a map\n");
		return (EXIT_FAILURE);
	}
	file = argv[1];
	if (check_file_extention(file) == EXIT_FAILURE)
	{
		printf("Error\n -The expected map format is '.cub'\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_file_extention(char *file)
{
	char	**file_tab;
	int		len;

	file_tab = ft_split(file, '.');
	len = ft_len_tab(file_tab);
	if (len < 2)
		return (ft_free_tab(file_tab), EXIT_FAILURE);
	if (!ft_strcmp(file_tab[len - 1], "cub"))
		return (ft_free_tab(file_tab), EXIT_SUCCESS);
	return (ft_free_tab(file_tab), EXIT_FAILURE);
}
