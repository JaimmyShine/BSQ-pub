/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <jcayuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:04:14 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/29 15:04:18 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_reader.h"
#include "ft_utils.h"

int	get_map_data(t_map *map, char *line)
{
	char	*n_of_lines;
	int		line_len;

	line_len = ft_strlen(line);
	if (line_len < 4)
		return (-1);
	if (!ft_str_is_printable(line))
		return (-1);
	n_of_lines = malloc(sizeof(char) * (line_len - 3 + 1));
	if (!n_of_lines)
		return (-1);
	ft_strncpy(n_of_lines, line, line_len - 3);
	n_of_lines[line_len - 3] = '\0';
	if (!ft_str_is_numeric(n_of_lines))
	{
		free(n_of_lines);
		return (-1);
	}
	map->rows = ft_atoi(n_of_lines);
	map->empty = line[line_len - 3];
	map->obstacle = line[line_len - 2];
	map->fill = line[line_len - 1];
	free(n_of_lines);
	return (0);
}

int	check_map_content(t_map *map, char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i] != NULL)
	{
		if (ft_strlen(lines[i]) != map->cols)
		{
			return (0);
		}
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] != map->empty
				&& lines[i][j] != map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	if (i != map->rows)
		return (0);
	return (1);
}

int	get_map_content(t_map *map, char **lines)
{
	int	i;

	map->cols = ft_strlen(lines[0]);
	if (!check_map_content(map, lines))
		return (-1);
	map->content = malloc(sizeof(char *) * map->rows);
	i = 0;
	while (lines[i] != NULL)
	{
		map->content[i] = ft_strdup(lines[i]);
		i++;
	}
	return (0);
}

int	parse_map(t_map *map, char *buf)
{
	char	**lines;

	lines = split_lines(buf);
	if (!lines)
		return (-1);
	if (get_map_data(map, lines[0]))
	{
		free_split_lines(lines);
		return (-1);
	}
	if (get_map_content(map, lines + 1))
	{
		free_split_lines(lines);
		return (-1);
	}
	free_split_lines(lines);
	return (0);
}

char	**split_lines(char *buf)
{
	char	**lines;

	lines = ft_split(buf, "\n");
	if (!lines)
		return (NULL);
	return (lines);
}
