/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:40:48 by mbouaza           #+#    #+#             */
/*   Updated: 2022/11/19 16:59:56 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// return the size of my putnbr in base16 //

static int	len_hexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

// for %X //

int	ft_putnbr_hex_maj(unsigned int n, int *error)
{
	int	len;

	len = len_hexa(n);
	if (n >= 16)
	{
		ft_putnbr_hex_maj(n / 16, error);
		ft_putnbr_hex_maj(n % 16, error);
	}
	else if (n < 10)
		ft_putchar(n + 48, error);
	else
		ft_putchar(n + 55, error);
	return (len);
}
