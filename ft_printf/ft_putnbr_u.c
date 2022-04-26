/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:45:10 by creyt             #+#    #+#             */
/*   Updated: 2021/11/22 18:30:06 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *count)
{
	if (n < 0)
	{
		n -= UINT_MAX - 1;
		ft_putnbr_u(n, count);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar_c((n + '0'), count);
	else
	{
		ft_putnbr_u(n / 10, count);
		ft_putnbr_u(n % 10, count);
	}
}
