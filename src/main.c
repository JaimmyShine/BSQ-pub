/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:44:36 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/29 16:58:49 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_utils.h"

int	bsq(int fd);

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc < 2)
	{
		bsq(-1);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_putstr("map error\n");
		else
			bsq(fd);
		if (i < argc - 1)
			ft_putchar('\n');
		close(fd);
		i++;
	}
	return (0);
}
