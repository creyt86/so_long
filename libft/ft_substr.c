/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:30:44 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 11:30:37 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size < len)
		len = size;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	while (i < len && start < size)
	{
		s2[i] = ((char)s[start]);
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
