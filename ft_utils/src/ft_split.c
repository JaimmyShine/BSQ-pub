/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:10:42 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/26 11:49:23 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	**allocate_array(char *str, char *charset)
{
	int		word_count;
	int		on_sep;
	char	**arr;

	word_count = 0;
	on_sep = 1;
	while (*str != '\0')
	{
		if (is_separator(*str, charset))
		{
			on_sep = 1;
		}
		else if (on_sep)
		{
			word_count++;
			on_sep = 0;
		}
		str++;
	}
	arr = malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	arr[word_count] = NULL;
	return (arr);
}

char	*ft_duplicate_str(char *src, int n)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

int	ft_split_helper(char **result, char *str, char *charset)
{
	int		word_len;
	int		k;

	k = 0;
	word_len = 0;
	while (*str != '\0')
	{
		if (is_separator(*str, charset) && word_len > 0)
		{
			result[k] = ft_duplicate_str(str - word_len, word_len);
			if (!result[k++])
				return (0);
			word_len = 0;
		}
		else if (!is_separator(*(str++), charset))
			word_len++;
	}
	if (word_len > 0)
	{
		result[k] = ft_duplicate_str(str - word_len, word_len);
		if (!result[k])
			return (0);
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = allocate_array(str, charset);
	if (!result)
		return (NULL);
	if (!ft_split_helper(result, str, charset))
		return (NULL);
	return (result);
}
