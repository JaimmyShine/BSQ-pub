/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:29:46 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/26 17:12:55 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		n;
	char	*new_str;

	i = 0;
	n = ft_strlen(src);
	new_str = malloc(sizeof(char) * (n + 1));
	if (!new_str)
		return (NULL);
	while (i < n)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
