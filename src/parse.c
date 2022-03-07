/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:54 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/07 15:05:25 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (argv[i])
	{
		while (argv[i][y])
		{
			if (ft_isdigit(argv[i][y]) == 1)
				return (2);
			y++;
		}
		y = 0;
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i++]) > 1000)
			return (3);
	}
	return (0);
}
