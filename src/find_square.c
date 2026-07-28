/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuedoscorpion <psuedoscorpion@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:09:16 by psuedoscorp       #+#    #+#             */
/*   Updated: 2026/07/29 00:07:12 by psuedoscorp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "solver.h"

void    add_square(t_map *map, int max_size, int max_y, int max_x)
{
    int i;
    int j;
    
    i = max_y - max_size + 1;
    while(i <= max_y)
    {
        j = max_x - max_size + 1;
        while(j <= max_x)
        {
            map->content[i][j] = map->fill;
            j++;
        }
        i++;
    }
}

int **allocate_tab(t_map *map)
{
    int **map_int;
    int i;

    i = 0;
    map_int = malloc(sizeof(int *) * map->rows);
    if (!map_int)
        return (NULL);
    while(i < map->rows)
    {
        map_int[i] = malloc(sizeof(int) * map->cols);
        if (!map_int[i])
            return (NULL);
        i++;
    }
    return (map_int);
}

void    free_int_map(int **tab, t_map *map)
{
    int i;

    i = 0;
    while(i < map->rows)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
int     tab_int_value(t_map *map, int **map_int, int i, int j)
{
    if(map->content[i][j] == map->obstacle)
        return (0);
    else if(i == 0 || j == 0)
        return (1);
    else
        return (min_val(map_int[i-1][j], map_int[i][j-1], map_int[i-1][j-1]) + 1);
}

void    map_solver(t_map *map)
{
    int max_size;
    int max_y;
    int max_x;
    int **map_int;
    int i;
    int j;

    map_int = allocate_tab(map);
    max_size = 0;
    i = -1;
    while (++i < map->rows)
    {
        j = -1;
        while (++j < map->cols)
        {
            map_int[i][j] = tab_int_value(map, map_int, i, j);
            if(map_int[i][j] > max_size && (max_y = i) == i && (max_x = j) == j)
                max_size = map_int[i][j];
        }
    }
    add_square(map, max_size, max_y, max_x);
    free_int_map(map_int, map);
}
