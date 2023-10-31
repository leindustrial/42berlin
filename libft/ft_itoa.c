/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:14:14 by ole               #+#    #+#             */
/*   Updated: 2023/05/10 10:14:43 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long num)
{
	size_t	count;

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

static char	*ft_transform(char *ptr, long num, int count, int mult)
{
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (ptr == 0)
		return (ptr);
	if (num < 0)
	{
		mult++;
		num = -num;
	}
	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	ptr[count] = '\0';
	while (--count)
	{
		ptr[count] = (num % 10) + '0';
		num = num / 10;
	}
	if (mult == 1)
		ptr[0] = '-';
	else
		ptr[0] = (num % 10) + '0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	num;
	size_t	count;
	int		mult;

	ptr = 0;
	num = n;
	count = ft_numlen(num);
	mult = 0;
	ptr = ft_transform(ptr, num, count, mult);
	return (ptr);
}
