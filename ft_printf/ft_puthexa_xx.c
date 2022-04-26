/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:29:13 by creyt             #+#    #+#             */
/*   Updated: 2021/11/19 14:22:10 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_xx(unsigned int n, int *count, int first)
{
	unsigned int	hex;
	int				letter;
	int				len;

	len = ft_len_nbr(n);
	letter = 'A';
	if (len == 0 && first)
		return (ft_putchar_c('0', count));
	if (n > 0)
	{
		ft_puthexa_xx(n / 16, count, 0);
		hex = n % 16;
		if (hex > 9)
			ft_putchar_c(hex + letter - 10, count);
		else
			ft_putchar_c(hex + '0', count);
	}
}
