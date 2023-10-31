/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:50:20 by ole               #+#    #+#             */
/*   Updated: 2023/05/04 11:20:46 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = 0;
	i = dlen;
	if (size == 0)
		return (slen);
	if (size < dlen)
		return (slen + size);
	else
	{
		while (src[j] != '\0' && (dlen + j) < size)
			dst[i++] = src[j++];
		if ((dlen + j) == size && dlen < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (slen + dlen);
	}
}
