/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:29:22 by creyt             #+#    #+#             */
/*   Updated: 2021/11/22 18:28:31 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_d(int nb, int *count)
{
	if (nb == -2147483648)
		ft_putstr_s("-2147483648", count);
	else if (nb >= 0 && nb <= 9)
		ft_putchar_c(nb + '0', count);
	else if (nb < 0)
	{
		ft_putchar_c('-', count);
		ft_putnbr_d(nb * (-1), count);
	}
	else
	{
		ft_putnbr_d(nb / 10, count);
		ft_putnbr_d(nb % 10, count);
	}
}
