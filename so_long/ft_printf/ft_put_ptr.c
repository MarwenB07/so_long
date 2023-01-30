/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:31:44 by mbouaza           #+#    #+#             */
/*   Updated: 2022/11/19 17:23:31 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

// count the len of my the number into base16 //
// the i + 2 is for the '0x' in the start of my %p, to have a good allocation //

static int	put_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len + 2);
}

// if my malloc fail, it's return 0 and give -1 to error //

static int	error_return(int *error)
{
	*error = -1;
	return (0);
}

// for %p //

int	ft_put_ptr(unsigned long long n, int *error)
{
	char	*ptr;
	char	*base16;
	int		len;
	int		i;

	len = put_ptr_len(n);
	i = 0;
	base16 = "0123456789abcdef";
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (error_return(error));
	ptr[len] = '\0';
	while (len > 2)
	{
		i = n % 16;
		n = n / 16;
		ptr[--len] = base16[i];
	}
	ptr[0] = '0';
	ptr[1] = 'x';
	i = 0;
	i = ft_putstr(ptr, error);
	free(ptr);
	return (i);
}
