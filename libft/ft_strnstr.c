/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:29:05 by ole               #+#    #+#             */
/*   Updated: 2023/05/08 12:53:50 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_str;

	big_str = (char *)big;
	if (little[0] == '\0')
		return (big_str);
	i = 0;
	while (big_str[i] != '\0' && i < len)
	{
		j = 0;
		while ((big_str[i + j] == little[j]) && (i + j < len))
		{
			if ((little[j + 1]) == '\0')
				return (&big_str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
