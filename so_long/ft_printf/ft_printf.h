/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:16 by mbouaza           #+#    #+#             */
/*   Updated: 2022/11/19 17:24:43 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// int //

int	ft_putnbr(int n, int *error);
int	ft_putnbr_unsigned(unsigned int n, int *error);
int	ft_putchar(int n, int *error);
int	ft_putstr(const char *str, int *error);
int	ft_putnbr_hex_maj(unsigned int n, int *error);
int	ft_putnbr_hex_min(unsigned int n, int *error);
int	ft_put_ptr(unsigned long long nbr, int *error);
int	ft_printf(const char *format, ...);

#endif
