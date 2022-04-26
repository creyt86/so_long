/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:51:23 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 11:26:19 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	else
	{
		while (s[i])
		{
			s2[i] = s[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
}
