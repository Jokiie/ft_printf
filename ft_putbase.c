/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:32:22 by ccodere           #+#    #+#             */
/*   Updated: 2024/02/27 18:03:36 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putbase(long n, int base)
{
	int		count;
	char	*characters;

	count = 0;
	characters = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putbase(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_putchar(characters[n]));
	}
	else
	{
		count = ft_putbase(n / base, base);
		return (count + ft_putbase(n % base, base));
	}
}
