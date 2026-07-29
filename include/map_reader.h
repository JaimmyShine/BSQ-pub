/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:00:08 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/28 23:44:50 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H
# include "s_map.h"

int		get_map_data(t_map *map, char *line);
int		parse_map(t_map *map, char *buf);

char	**split_lines(char *buf);
int		check_map_is_valid(char *buf);

#endif
