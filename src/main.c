/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:06:56 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/07 13:36:09 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	int	i;

	i = philo(argc, argv);
	if (i != 0)
		get_error(i);
	printf("%s\n", argv[0]);
	return (0);
}