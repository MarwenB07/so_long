/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:23:40 by mbouaza           #+#    #+#             */
/*   Updated: 2022/11/19 17:22:26 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

// return the size of my putnbr //

static int	putnbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// for %d and %i //

int	ft_putnbr(int n, int *error)
{
	int	len;

	len = putnbr_len(n);
	if (n == -2147483648)
		ft_putstr("-2147483648", error);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-', error);
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10, error);
			ft_putnbr(n % 10, error);
		}
		else
			ft_putchar(n + '0', error);
	}
	return (len);
}
