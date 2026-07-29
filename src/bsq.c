/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <jcayuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:46:17 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/29 17:17:36 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_utils.h"
#include "map_reader.h"
#include "solver.h"

void	read_file(int fd, char **buffer)
{
	char	c;
	char	*new_buf;
	int		len;
	int		cap;
	int		i;

	len = 0;
	cap = 64;
	*buffer = malloc(sizeof(char) * (cap));
	while (read(fd, &c, 1) > 0)
	{
		(*buffer)[len] = c;
		len++;
		if (len == cap)
		{
			cap = cap * 2;
			new_buf = malloc(sizeof(char) * (cap));
			i = -1;
			while (++i < len)
				new_buf[i] = (*buffer)[i];
			free(*buffer);
			*buffer = new_buf;
		}
	}
	(*buffer)[len] = '\0';
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->content[i]);
		ft_putchar('\n');
		i++;
	}
}

int	bsq(int fd)
{
	t_map	map;
	char	*buffer;
	int		i;

	if (fd == -1)
		fd = STDIN_FILENO;
	buffer = NULL;
	read_file(fd, &buffer);
	if (parse_map(&map, buffer))
	{
		free(buffer);
		ft_putstr("map error\n");
		return (-1);
	}
	map_solver(&map, -1, -1);
	print_map(&map);
	free(buffer);
	i = 0;
	while (i < map.rows)
	{
		free(map.content[i]);
		i++;
	}
	free(map.content);
	return (0);
}
