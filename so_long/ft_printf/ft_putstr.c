/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:51:37 by mbouaza           #+#    #+#             */
/*   Updated: 2022/11/19 17:05:47 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

// for %s //

int	ft_putstr(const char *str, int *error)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", error);
		return (6);
	}
	else
	{
		while (str[len] != '\0')
			ft_putchar(str[len++], error);
	}
	return (len);
}
