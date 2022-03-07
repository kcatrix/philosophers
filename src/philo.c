/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:30:28 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/07 14:17:18 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo(int argc, char **argv)
{
	if (parse(argc, argv) != 0)
		return(parse(argc, argv));
	return (0);
}