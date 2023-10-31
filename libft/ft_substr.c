/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:09:30 by ole               #+#    #+#             */
/*   Updated: 2023/05/10 10:12:01 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start > s_len)
		len = 0;
	if (len > (s_len - start))
		len = (s_len - start);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
