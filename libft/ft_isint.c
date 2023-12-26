/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:33:50 by ole               #+#    #+#             */
/*   Updated: 2023/06/16 11:36:46 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(int len, long int *arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}