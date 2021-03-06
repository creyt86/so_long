/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:42:49 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 11:21:09 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr_b;

	i = 0;
	ptr_b = b;
	while (len > i)
	{
		ptr_b[i] = c;
		i++;
	}
	return (b);
}
