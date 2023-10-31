/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:56:16 by ole               #+#    #+#             */
/*   Updated: 2023/05/08 13:45:38 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	size_t			i;
	unsigned char	*str;

	result = malloc(size * count);
	if (result == 0)
		return (0);
	i = 0;
	str = (unsigned char *)result;
	while (i < (size * count))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
