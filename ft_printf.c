/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:22:22 by ccodere           #+#    #+#             */
/*   Updated: 2024/02/24 11:53:36 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parse_pointer(char format, va_list arg_ptr)
{
	int						count;
	unsigned long			ptr;
	char					buffer[20];
	char					*ptr_str;

	count = 0;
	if (format == '\0')
		return (-1);
	if (format == 'p')
	{
		ptr = (unsigned long)va_arg(arg_ptr, void *);
		if (ptr == '\0')
			count += ft_putstr("0x0");
		else
		{
			ptr_str = ft_itoa_base(ptr, buffer, 16);
			count += ft_putstr("0x");
			count += ft_putstr(ptr_str);
		}
	}
	else
		count += ft_putchar(format);
	return (count);
}

int	ft_parse_chars(char format, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (format == '\0')
		return (-1);
	if (format == 'c')
		count += ft_putchar(va_arg(arg_ptr, int));
	else if (format == 's')
		count += ft_putstr(va_arg(arg_ptr, char *));
	else if (format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(format);
	return (count);
}

int	ft_parse_digits(char format, va_list arg_ptr)
{
	int		count;

	count = 0;
	if (format == '\0')
		return (-1);
	if (format == 'd' || format == 'i')
	{
		if (format == '0' && ((format + 1) == 'x' || (format + 1) == 'X'))
			count += ft_putbase_hex((long)(va_arg(arg_ptr, unsigned int)), 0);
		else if (count == '0')
			count += ft_putbase((long)(va_arg(arg_ptr, unsigned int)), 8);
		else
			count += ft_putbase((long)(va_arg(arg_ptr, int)), 10);
	}
	else if (format == 'u')
		count += ft_putbase((long)(va_arg(arg_ptr, unsigned int)), 10);
	else if (format == 'x')
		count += ft_putbase_hex((long)(va_arg(arg_ptr, unsigned int)), 0);
	else if (format == 'X')
		count += ft_putbase_hex((long)(va_arg(arg_ptr, unsigned int)), 1);
	else
		count += ft_putchar(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	int			count;

	va_start(arg_ptr, format);
	count = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == '%')
				count += ft_parse_chars(*format, arg_ptr);
			else if (*format == 'p')
				count += ft_parse_pointer(*format, arg_ptr);
			else
				count += ft_parse_digits(*format, arg_ptr);
		}
		else
			count += ft_putchar(*format);
		++format;
	}
	va_end(arg_ptr);
	return (count);
}
