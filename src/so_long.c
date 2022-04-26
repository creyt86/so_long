/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:51:35 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:42:30 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	gm;
	char	*file;
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_argc(argc);
	gm.win.win = NULL;
	file = argv[1];
	gm.mlx = mlx_init();
	read_map(&gm, file);
	check_map(&gm, file);
	check_item(&gm);
	init_item(&gm);
	gm.win.win = mlx_new_window(gm.mlx, gm.win.wid, gm.win.hei, TITLE_TXT);
	define_image(&gm, x, y);
	draw_map(&gm);
	mlx_loop_hook(gm.mlx, key_hook, &gm);
	mlx_loop(gm.mlx);
}
