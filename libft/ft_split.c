/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:11:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/18 21:04:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_total_words(char const *s, char sep)
{
	size_t	words_count;

	words_count = 0;
	if (!*s)
		return (words_count);
	if (!ft_strchr(s, sep))
		return (1);
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			while (*s && *s != sep)
				s++;
			words_count++;
		}
	}
	return (words_count);
}

static char	*ft_strcpy_custom(char *dst, char *start, size_t *len)
{
	size_t	index;

	index = 0;
	while (index < *len)
	{
		*dst = start[index];
		index++;
		dst++;
	}
	*dst = '\0';
	*len = 0;
	return (dst);
}

static char	**create_words(char **split, const char *s,
char c, size_t split_index)
{
	char	*start_word;
	size_t	word_len;

	word_len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			start_word = (char *)s;
			while (*s && *s != c)
			{
				word_len++;
				s++;
			}
			split[split_index] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!split[split_index])
				return (NULL);
			ft_strcpy_custom(split[split_index++], start_word, &word_len);
		}
	}
	split[split_index] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_index;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (get_total_words(s, c) + 1));
	if (!split)
		return (NULL);
	split_index = 0;
	split = create_words(split, s, c, split_index);
	if (!split)
		return (NULL);
	return (split);
}
