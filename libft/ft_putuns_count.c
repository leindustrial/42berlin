/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:40:04 by ole               #+#    #+#             */
/*   Updated: 2023/03/30 10:52:11 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putuns_count(long nbr)
{
	int	len;

	if (nbr == 0)
		return (write (1, "0", 1));
	len = 0;
	len += ft_count(nbr);
	if (nbr >= 10)
	{
		ft_putuns_count(nbr / 10);
		ft_putuns_count(nbr % 10);
	}
	else
	{
		nbr = nbr + '0';
		write (1, &nbr, 1);
	}
	return (len);
}
