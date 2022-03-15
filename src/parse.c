/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:54 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/15 14:42:16 by kcatrix          ###   ########.fr       */
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

void	init_struct(int argc, char **argv, t_philo *P)
{
	P->number_of_philo = ft_atoi(argv[1]);
	/*P->time_to_die = ft_atoi(argv[2]);
	P->time_to_eat = ft_atoi(argv[3]);
	P->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		P->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		P->number_of_times_each_philosopher_must_eat = -1;*/

}

void	get_time(void)
{
	struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    printf("milliseconds: %lld\n", milliseconds);
    //return milliseconds;
}