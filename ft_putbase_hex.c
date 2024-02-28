/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:22:22 by ccodere           #+#    #+#             */
/*   Updated: 2024/02/27 17:53:36 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putbase_hex(long n, int uppercase)
{
	int		count;
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 0)
	{
		n = (unsigned int)-n;
		return (ft_putbase_hex(n / 16, uppercase) + 1);
	}
	else if (n < 16)
	{
		return (ft_putchar(base[n]));
	}
	else
	{
		count = ft_putbase_hex(n / 16, uppercase);
		return (count + ft_putbase_hex(n % 16, uppercase));
	}
}
