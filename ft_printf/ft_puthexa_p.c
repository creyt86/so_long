/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:44:17 by creyt             #+#    #+#             */
/*   Updated: 2021/11/22 14:54:20 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_p(void *ptr, int *count)
{
	ft_putstr_s("0x", count);
	ft_puthexa_x((unsigned long)ptr, count, 1);
}
