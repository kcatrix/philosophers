/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/03/21 15:51:26 by kevyn            ###   ########.fr       */
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

struct s_philo;

typedef struct s_philo_inside
{
	int 			i;
	pthread_t 		*th;
	pthread_mutex_t fork;
	int				action;
	int				die;
 	struct s_philo 	*P;
}	t_philo_i;

typedef struct s_philo
{
	int				i;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		time;
	pthread_mutex_t mutex;
	t_philo_i		*philo;
}	t_philo;

int		philo(int argc, char **argv, t_philo *P);
void	init_struct(int argc, char **argv, t_philo *P);
char	get_error(int i);
size_t	ft_strlen(const char *s);
long	get_time(void);
void 	eat(t_philo_i *p);
int		ft_isdigit(int c);
void 	*action(void *arg);
void	dodo(t_philo_i *p);
int		die(t_philo_i *p);
int		ft_atoi(const char *str);
int 	parse(int argc, char **argv);

#endif