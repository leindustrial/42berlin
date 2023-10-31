/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:24:30 by ole               #+#    #+#             */
/*   Updated: 2023/06/07 15:24:34 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_writehex(unsigned int nbr, char format)
{
	if (nbr >= 16)
	{
		ft_writehex((nbr / 16), format);
		ft_writehex((nbr % 16), format);
	}
	else if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		if (format == 'x')
			ft_putchar(nbr - 10 + 'a');
		if (format == 'X')
			ft_putchar(nbr - 10 + 'A');
	}
}

int	ft_puthex(unsigned long long int nbr, char format)
{
	if (nbr == 0)
		return (write (1, "0", 1));
	else
		ft_writehex(nbr, format);
	return (ft_hexlen (nbr));
}
