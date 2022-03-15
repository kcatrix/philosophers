/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/03/15 14:35:53 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "macro.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t mutex;
}	t_philo;

int		philo(int argc, char **argv, t_philo *P);
void	init_struct(int argc, char **argv, t_philo *P);
char	get_error(int i);
size_t	ft_strlen(const char *s);
void	get_time(void);
int		ft_isdigit(int c);
void 	*action(void *arg);
int		ft_atoi(const char *str);
int 	parse(int argc, char **argv);

#endif