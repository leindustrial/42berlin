/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:42:54 by ole               #+#    #+#             */
/*   Updated: 2023/05/08 11:16:35 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ptr = 0;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
		{
			ptr = &str[i];
			return (ptr);
		}
		i++;
	}
	return (0);
}
