/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:46:16 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 11:30:16 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset( char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	i = 0;
	start = 0;
	while (s1[i] && ft_isset(s1[i], set))
	{
		start++;
		i++;
	}
	end = ft_strlen(s1) - 1;
	while (end > start && ft_isset(s1[end], set))
		end--;
	s2 = malloc(sizeof(char) * (end - start + 2));
	if (!s2)
		return (0);
	i = 0;
	while (start <= end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}
