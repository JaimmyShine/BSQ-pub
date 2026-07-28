/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:00:08 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/28 20:06:05 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H
# include "s_map.h"

void	get_map_data(t_map *map, char *line);
void	parse_map(t_map *map, char *buf);

#endif
