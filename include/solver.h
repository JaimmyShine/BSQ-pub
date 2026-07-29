/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuedoscorpion <psuedoscorpion@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:04:51 by psuedoscorp       #+#    #+#             */
/*   Updated: 2026/07/29 17:15:47 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "s_map.h"

void	map_solver(t_map *map, int i, int j);
int		tab_int_value(t_map *map, int **map_int, int i, int j);
void	add_square(t_map *map, int max_size, int max_y, int max_x);

int		**allocate_tab(t_map *map);
void	free_int_map(int **tab, t_map *map);

int		min_val(int a, int b, int c);

#endif
