/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:46:17 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/29 13:17:16 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_utils.h"
#include "map_reader.h"

int	bsq(int fd)
{
	t_map	map;
	char	buffer[4096];
	int		size;
	int		i;

	size = read(fd, buffer, 4096);
	if (size < 0)
		return (-1);
	if (parse_map(&map, buffer))
	{
		ft_putstr("map error\n");
		return (-1);
	}
	i = 0;
	while (i < map.rows)
	{
		ft_putstr(map.content[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
