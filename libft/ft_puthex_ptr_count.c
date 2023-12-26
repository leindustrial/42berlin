/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:24:30 by ole               #+#    #+#             */
/*   Updated: 2023/06/07 15:24:34 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_hex(unsigned long long nbr, char format)
{
	if (nbr >= 16)
	{
		ft_write_hex((nbr / 16), format);
		ft_write_hex((nbr % 16), format);
	}
	else 
	{
		if (nbr < 10)
			nbr = nbr + '0';
		else
		{
			if (format == 'x' || format == 'p')
				nbr = nbr - 10 + 'a';
			else if (format == 'X')
				nbr = nbr - 10 + 'A';
		}
		write (1, &nbr, 1);
	}
}

int	ft_puthex_ptr_count(unsigned long long nbr, char format)
{
	int	len;

	if (nbr == 0 && (format == 'x' || format == 'X'))
		return (write (1, "0", 1));
	if (nbr == 0 && format == 'p')
		return (write(1, "(nil)", 5));
	len = 0;
	if (format == 'p')
		len += write(1, "0x", 2);
	ft_write_hex(nbr, format);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
