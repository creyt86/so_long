/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:26:00 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 13:03:47 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(t_game *gm)
{
	if (gm)
		exit (0);
	return (0);
}

int	key_hook(t_game *gm)
{
	mlx_hook(gm->win.win, 17, 0L << 0, exit_window, gm);
	mlx_hook(gm->win.win, 2, 1L << 0, key_press, gm);
	return (0);
}

int	key_press(int keycode, t_game *gm)
{
	if (!check_wall(keycode, gm))
	{
		draw_water(gm, gm->player.x, gm->player.y);
		if (keycode == KEY_ESC)
			exit_window(gm);
		else if (keycode == KEY_W || keycode == KEY_UP)
			gm->player.y -= 1;
		else if (keycode == KEY_A || keycode == KEY_LFT)
			gm->player.x -= 1;
		else if (keycode == KEY_S || keycode == KEY_DW)
			gm->player.y += 1;
		else if (keycode == KEY_D || keycode == KEY_RGT)
			gm->player.x += 1;
		else
			ft_printf(ERR_TOUCH);
		add_item(gm, gm->player.x, gm->player.y);
		draw_duck(gm, gm->player.x, gm->player.y);
	}
	gm->steps++;
	ft_printf("steps : %d\n", gm->steps);
	return (0);
}
