/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_img_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:47:42 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:55:28 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charge_img(t_game *gm, char *path, int x, int y)
{
	char	*img;

	img = mlx_xpm_file_to_image(gm->mlx, path, &gm->win.wid, &gm->win.hei);
	gm->img.img = img;
	mlx_put_image_to_window(gm->mlx, gm->win.win, gm->img.img, x, y);
}

void	define_image(t_game *gm, int i, int j)
{
	if (gm->map.map[i][j] == '1')
		draw_wall(gm, j, i);
	else if (gm->map.map[i][j] == '0')
		draw_water(gm, j, i);
	else if (gm->map.map[i][j] == 'P')
	{
		draw_duck(gm, j, i);
		gm->player.x = j;
		gm->player.y = i;
	}
	else if (gm->map.map[i][j] == 'C')
		draw_bread(gm, j, i);
	else if (gm->map.map[i][j] == 'E')
		draw_exit(gm, j, i);
	else if (gm->map.map[i][j] == '\n')
		;
	else
		error_close(ERR_CHAR_TXT);
}

void	draw_map(t_game *gm)
{
	int	x;
	int	y;

	x = 0;
	while (x < gm->map.hei)
	{
		y = 0;
		while (y < gm->map.wid)
		{
			define_image(gm, x, y);
			y++;
		}
		x++;
	}
}
