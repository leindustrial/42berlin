/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:19:04 by ole               #+#    #+#             */
/*   Updated: 2023/05/29 16:24:46 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_agr_parsing(char ch, va_list args)
{
	if (ch == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (ch == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (ch == 'd' || ch == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	else if (ch == 'u')
		return (ft_putuns_count(va_arg(args, unsigned int)));
	else if (ch == 'p')
		return (ft_puthex_ptr_count(va_arg(args, unsigned long), ch));
	else if (ch == 'x' || ch == 'X')
		return (ft_puthex_ptr_count(va_arg(args, unsigned int), ch));
	else if (ch == '%')
		return (ft_putchar_count('%'));
	else
	{
		write (1, "%", 1);
		write (1, &ch, 1);
		return (2);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	va_start(args, format);
	i = 0;
	if (!format)
		return (-1);
	print_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_len += ft_agr_parsing(format[i + 1], args);
			i += 2;
		}
		else
		{
			write (1, &format[i], 1);
			print_len++;
			i++;
		}
	}
	va_end(args);
	return (print_len);
}
