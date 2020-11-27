/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:17:25 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:34:30 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*ft_malloc_words(char const *s, char c)
{
	char			*word;
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(word);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**result;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) *
		(ft_count_words(s, c) + 1))))
	{
		free(result);
		return (NULL);
	}
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			result[i++] = ft_malloc_words(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}
