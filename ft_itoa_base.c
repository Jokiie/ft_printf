/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:32:22 by ccodere           #+#    #+#             */
/*   Updated: 2024/02/27 19:03:36 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(unsigned long value, char *buffer, int base)
{
	const char		*chars;
	char			*ptr;
	unsigned long	temp;
	int				len;

	chars = "0123456789abcdef";
	ptr = buffer;
	temp = value;
	len = 0;
	while (temp != 0)
	{
		temp /= base;
		len++;
	}
	ptr += len;
	*ptr = '\0';
	while (value != 0)
	{
		*(--ptr) = chars[value % base];
		value /= base;
	}
	return (ptr);
}
