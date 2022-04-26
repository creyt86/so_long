/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:30:01 by creyt             #+#    #+#             */
/*   Updated: 2022/04/25 17:05:26 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_end(int keycode, t_game *gm)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (gm->map.map[gm->player.y - 1][gm->player.x]
				== 'E' && gm->item <= 0)
			return (1);
	}
	else if (keycode == KEY_A || keycode == KEY_LFT)
	{
		if (gm->map.map[gm->player.y][gm->player.x - 1]
				== 'E' && gm->item <= 0)
			return (1);
	}
	else if (keycode == KEY_S || keycode == KEY_DW)
	{
		if (gm->map.map[gm->player.y + 1][gm->player.x]
				== 'E' && gm->item <= 0)
			return (1);
	}
	else if (keycode == KEY_D || keycode == KEY_RGT)
	{
		if (gm->map.map[gm->player.y][gm->player.x + 1]
				== 'E' && gm->item <= 0)
			return (1);
	}
	return (0);
}

int	check_wall_or_end(t_game *gm, int x, int y)
{
	if (gm->map.map[y][x] == '1')
		return (1);
	if (gm->map.map[y][x] == 'E' && gm->item > 0)
		return (1);
	return (0);
}

int	check_wall(int keycode, t_game *gm)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (check_wall_or_end(gm, gm->player.x, gm->player.y - 1))
			return (1);
	}
	else if (keycode == KEY_A || keycode == KEY_LFT)
	{
		if (check_wall_or_end(gm, gm->player.x - 1, gm->player.y))
			return (1);
	}
	else if (keycode == KEY_S || keycode == KEY_DW)
	{
		if (check_wall_or_end(gm, gm->player.x, gm->player.y + 1))
			return (1);
	}
	else if (keycode == KEY_D || keycode == KEY_RGT)
	{
		if (check_wall_or_end(gm, gm->player.x + 1, gm->player.y))
			return (1);
	}
	return (0);
}
