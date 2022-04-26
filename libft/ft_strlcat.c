/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:29:09 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 11:27:31 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = dstsize;
	dstlen = (size_t)ft_strlen(dst);
	srclen = (size_t)ft_strlen(src);
	while (*dst != '\0')
	{
		dst++;
		if (i > 0)
			i--;
	}
	while (*src != '\0' && i > 1)
	{
		*dst = *src;
		dst++;
		src++;
		i--;
	}
	*dst = '\0';
	if (dstsize > dstlen)
		return (dstlen + srclen);
	return (dstsize + srclen);
}
