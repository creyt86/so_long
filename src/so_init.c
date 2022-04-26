/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:03:13 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:55:09 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_item(t_game *gm)
{
	gm->steps = 0;
	gm->item = 0;
	gm->duck = 0;
	gm->exit = 0;
	gm->water = 0;
	gm->win.wid = gm->map.wid * 32;
	gm->win.hei = gm->map.hei * 32;
}

void	count_items(char c, t_game *gm)
{
	if (c == 'P')
		gm->duck++;
	if (c == 'E')
		gm->exit++;
	if (c == 'C')
		gm->item++;
	if (c == '0')
		gm->water++;
}

void	add_item(t_game *gm, int x, int y)
{
	if (gm->map.map[y][x] == 'C')
		gm->item--;
	if (gm->map.map[y][x] == 'E')
		exit (0);
}

void	error_close(char *str)
{
	ft_printf(str);
	exit (0);
}
