/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:30:28 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/07 15:44:11 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void* test()
{
	printf("the first execustion\n");
	sleep(3);
	printf("end");
}

int	philo(int argc, char **argv)
{
	//if (parse(argc, argv) != 0)
	//	return(parse(argc, argv));
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &test, NULL);
	pthread_create(&t2, NULL, &test, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
