/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:33:16 by ole               #+#    #+#             */
/*   Updated: 2023/05/10 11:17:34 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_mkstr(const char *s1, size_t start, size_t trim_len)
{
	char	*result;
	size_t	i;

	if (trim_len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < trim_len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	trim_len;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_trim(set, s1[start]))
		start++;
	while (ft_trim(set, s1[end]))
		end--;
	trim_len = end - (start - 1);
	ptr = ft_mkstr(s1, start, trim_len);
	return (ptr);
}
