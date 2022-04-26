/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:01:55 by creyt             #+#    #+#             */
/*   Updated: 2022/04/26 14:53:55 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	linecount(char *file)
{
	int		fd;
	int		nbline;
	int		ret;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	nbline = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 0)
			break ;
		if (ret < 0)
			return (-1);
		if (c == '\n')
			nbline++;
	}
	close(fd);
	return (nbline);
}

char	**map_height(t_game *gm, char *file)
{
	int		nbline;

	nbline = linecount(file);
	if (nbline <= 0)
		return (0);
	gm->map.hei = nbline;
	gm->map.map = (char **)malloc(sizeof(char *) * (nbline + 1));
	if (gm->map.map == NULL)
		return (0);
	return (gm->map.map);
}

int	read_map(t_game *gm, char *file)
{
	char	*tab;
	int		i;
	int		fd;

	i = 0;
	gm->map.map = map_height(gm, file);
	if (gm->map.map == 0)
		error_close(ERR_TXT);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < gm->map.hei)
	{
		tab = get_next_line(fd);
		if (!tab)
			return (0);
		gm->map.map[i++] = tab;
	}
	gm->map.wid = ft_strlen(gm->map.map[0] + 1);
	close(fd);
	return (0);
}
