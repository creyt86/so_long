/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:04:48 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:55:20 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
		error_close(MAP_ERR_TXT);
}

void	check_item(t_game *gm)
{
	if (gm->item <= 0)
		error_close(NO_C_TXT);
	if (gm->exit != 1)
		error_close(NO_E_TXT);
	if (gm->duck != 1)
		error_close(NO_P_TXT);
	if (gm->water <= 0)
		error_close(NO_W_TXT);
}

void	check_around_map(int i, int j, t_game *gm)
{
	if (gm->map.map[0][i] != '1' && gm->map.map[0][i] != '\n')
		error_close(MAP_ERR_HO);
	else if (gm->map.map[gm->map.hei - 1][i] != '1'
		&& gm->map.map[gm->map.hei - 1][i] != '\n')
		error_close(MAP_ERR_HO);
	else if (gm->map.map[j][0] != '1')
		error_close(MAP_ERR_HO);
	else if (gm->map.map[j][gm->map.wid - 1] != '1')
		error_close(MAP_ERR_HO);
}

void	check_map(t_game *gm, char *file)
{
	int	i;
	int	j;

	j = 0;
	init_item(gm);
	check_map_ber(file);
	while (j < gm->map.hei)
	{
		i = 0;
		while (gm->map.map[j][i] != '\0')
		{
			count_items(gm->map.map[j][i], gm);
			check_around_map(i, j, gm);
			i++;
		}
		j++;
	}
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf(ERR_ARG);
	}
}
