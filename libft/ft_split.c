/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:58:40 by ole               #+#    #+#             */
/*   Updated: 2023/06/06 12:59:15 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount( const char *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_words(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static char	**split(const char *s, char c, char **res, int start)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			res[j] = fill_words(s, start, i);
			if (res[j] == 0)
				return (ft_free(res, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		start;
	int		words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	res = ft_calloc((words + 1), sizeof(char *));
	if (!res)
		return (NULL);
	start = -1;
	res = split(s, c, res, start);
	return (res);
}
