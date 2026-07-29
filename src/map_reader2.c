/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <jcayuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:20:54 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/29 15:36:20 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_reader.h"
#include "ft_utils.h"

void	free_split_lines(char **sl)
{
	int	i;

	i = 0;
	while (sl[i] != NULL)
	{
		free(sl[i]);
		i++;
	}
	free(sl);
}
