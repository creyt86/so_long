/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:31:04 by creyt             #+#    #+#             */
/*   Updated: 2021/11/22 17:31:39 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(int i, const char *str, va_list ap, int *count)
{
	if (str[i + 1] == 'c')
		ft_putchar_c(va_arg(ap, int), count);
	else if (str[i + 1] == 's')
		ft_putstr_s(va_arg(ap, char *), count);
	else if (str[i + 1] == 'p')
		ft_puthexa_p(va_arg(ap, void *), count);
	else if (str[i + 1] == 'd')
		ft_putnbr_d(va_arg(ap, int), count);
	else if (str[i + 1] == 'i')
		ft_putnbr_i(va_arg(ap, int), count);
	else if (str[i + 1] == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), count);
	else if (str[i + 1] == 'x')
		ft_puthexa_x(va_arg(ap, unsigned int), count, 1);
	else if (str[i + 1] == 'X')
		ft_puthexa_xx(va_arg(ap, unsigned int), count, 1);
	else if (str[i + 1] == '%')
		ft_putstr_s("%", count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_c(str[i], &count);
		else
			check_type(i++, str, ap, &count);
		i++;
	}
	va_end(ap);
	return (count);
}
