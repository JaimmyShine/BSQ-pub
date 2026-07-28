/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuedoscorpion <psuedoscorpion@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:43:20 by psuedoscorp       #+#    #+#             */
/*   Updated: 2026/07/29 00:06:46 by psuedoscorp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int min_val(int a, int b, int c)
{
    int min;

    min = a; 
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return (min);
}
