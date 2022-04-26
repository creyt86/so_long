/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:15:43 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 10:35:41 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	size_t	len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (0);
	len = ft_intlen(n);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n)
	{
		str[len--] = ((n % 10) + 48);
		n = n / 10;
	}
	return (str);
}
