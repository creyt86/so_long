/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_draw_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:04:10 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:42:17 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *gm, int x, int y)
{
	charge_img(gm, IMG_WAL, x * IMG_W, y * IMG_H);
	gm->wall++;
}

void	draw_water(t_game *gm, int x, int y)
{
	charge_img(gm, IMG_WAT, x * IMG_W, y * IMG_H);
	gm->water++;
}

void	draw_duck(t_game *gm, int x, int y)
{
	charge_img(gm, IMG_GO, x * IMG_W, y * IMG_H);
	gm->duck++;
}

void	draw_bread(t_game *gm, int x, int y)
{
	charge_img(gm, IMG_BRD, x * IMG_W, y * IMG_H);
	gm->item++;
}

void	draw_exit(t_game *gm, int x, int y)
{
	charge_img(gm, IMG_EX, x * IMG_W, y * IMG_H);
	gm->exit++;
}
