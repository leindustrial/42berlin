/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:40:04 by ole               #+#    #+#             */
/*   Updated: 2023/03/30 10:52:11 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long int num, int base_len)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / base_len;
	}
	return (len);
}

static int	ft_check_base(const char *base)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(base);
	if (l == 0 || l == 1)
		return (1);
	i = 0;
	while (i < l)
	{
		j = i + 1;
		while (j <= l)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_base(long long int nbr, const char *base)
{
	int	base_len;
	int	len;

	if (nbr == 0)
		return (write (1, "0", 1));
	len = 0;
	base_len = ft_strlen(base);
	if (ft_check_base(base) == 1)
		return (0);
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
			len += ft_base(-nbr, base);
		}
		else if (nbr >= base_len)
		{
			ft_base(nbr / base_len, base);
			ft_base(nbr % base_len, base);
		}
		else
			write (1, &base[nbr], 1);
	}
	len += ft_len(nbr, base_len);
	return (len);
}
