/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:58:17 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/28 20:02:44 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

typedef struct s_map
{
	int		lines;
	char	empty;
	char	obstacle;
	char	fill;
	char	**content;
}	t_map;

#endif
