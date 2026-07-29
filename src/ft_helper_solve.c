/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <jcayuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:43:20 by psuedoscorp       #+#    #+#             */
/*   Updated: 2026/07/29 15:35:33 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	min_val(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}
