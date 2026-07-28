/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:04:14 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/28 20:19:39 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_reader.h"
#include "ft_utils.h"

void	get_map_data(t_map *map, char *line)
{
	char	*n_of_lines;
	int		line_len;

	line_len = ft_strlen(line);
	n_of_lines = malloc(sizeof(char) * (line_len - 3 + 1));
	ft_strncpy(n_of_lines, line, line_len - 3);
	n_of_lines[line_len - 3] = '\0';
}

void	parse_map(t_map *map, char *buf)
{
	
}
