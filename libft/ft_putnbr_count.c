/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:52 by ole               #+#    #+#             */
/*   Updated: 2023/05/08 16:01:53 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_count(int n)
{
	int	i;

	i = 0;
	i = ft_count(n);
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		ft_putnbr_count(n);
	}
	else if (n > 9)
	{
		ft_putnbr_count(n / 10);
		ft_putnbr_count(n % 10);
	}
	else
	{
		n = n + '0';
		write (1, &n, 1);
	}
	return (i);
}
