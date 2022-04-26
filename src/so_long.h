/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:18:49 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 11:55:12 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define TITLE_TXT "So_long"
# define START_TXT "Nourris le canard"
# define ERR_TXT "Error\n"
# define MAP_ERR_TXT "Pas la bonne extension!\n"
# define MAP_ERR_TXT2 "La map n'est pas rectangulaire !\n"
# define MAP_ERR_HO "La map a un trou !\n"
# define ERR_CHAR_TXT "La map ne doit contenir que des 0, 1, C, E, P !\n"
# define ERR_TOUCH "Mauvaise touche !\n"
# define ERR_ARG "Manquerait pas un argument ?!\n"
# define NO_P_TXT "Pas un seul canard, pas de jeu !\n"
# define NO_W_TXT "Pas d'eau pour le canard, pas de jeu !\n"
# define NO_C_TXT "Pas de pain pour nourrir le canard !\n"
# define NO_E_TXT "Pas de plage pour sortir de l'eau !\n"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DW 125
# define KEY_RGT 124
# define KEY_LFT 123
# define KEY_ESC 53
# define KEY_EXIT 17

# define IMG_WAL "./img/grass.xpm"
# define IMG_WAT "./img/water.xpm"
# define IMG_GO "./img/goose.xpm"
# define IMG_BRD "./img/bread.xpm"
# define IMG_EX "./img/exit.xpm"

# define IMG_W 32
# define IMG_H 32

typedef struct s_map
{
	char	**map;
	int		hei;
	int		wid;
}			t_map;

typedef struct s_image
{
	void	*img;
	int		wid;
	int		hei;
}			t_img;

typedef struct s_window
{
	void	*win;
	int		wid;
	int		hei;
}		t_win;

typedef struct s_position
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	int			item;
	int			duck;
	int			exit;
	int			water;
	int			wall;
	int			steps;
	t_map		map;
	t_img		img;
	t_img		tile;
	t_img		wal;
	t_img		wat;
	t_img		duc;
	t_img		brd;
	t_img		ex;
	t_win		win;
	t_pos		pos;
	t_player	player;
}			t_game;

void	print_txt(char *str, int len);
void	init_item(t_game *gm);
void	count_items(char c, t_game *gm);
void	add_item(t_game *gm, int x, int y);
void	check_map(t_game *gm, char *file);
void	check_item(t_game *gm);
void	check_argc(int argc);
int		linecount(char *file);
char	**map_height(t_game *gm, char *file);
int		read_map(t_game *gm, char *file);
void	charge_img(t_game *gm, char *path, int x, int y);
void	charge_image(t_game *gm);
void	define_image(t_game *gm, int x, int y);
void	draw_map(t_game *gm);
void	draw_wall(t_game *gm, int x, int y);
void	draw_water(t_game *gm, int x, int y);
void	draw_duck(t_game *gm, int x, int y);
void	draw_bread(t_game *gm, int x, int y);
void	draw_exit(t_game *gm, int x, int y);
int		check_end(int keycode, t_game *gm);
int		check_wall_or_end(t_game *gm, int x, int y);
int		check_wall(int keycode, t_game *gm);
int		key_hook(t_game *gm);
int		exit_window(t_game *gm);
int		key_press(int keycode, t_game *gm);
void	error_close(char *str);

#endif
