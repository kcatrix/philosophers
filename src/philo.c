/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:30:28 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/21 16:09:46 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



/*
	Mutex évite le programme de s'emmélé avec des execution succésive
	int	philo(int argc, char **argv)
{
    
	int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }
    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    free(res);
    return 0;
}

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void* fuel_filling(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void* car(void* arg) {
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40) {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}
*/
int philo(int argc, char* argv[], t_philo *P) 
{   

    if (parse(argc, argv) != 0)
        return(parse(argc, argv));
    init_struct(argc, argv, P);
    pthread_mutex_init(&P->mutex, NULL);
    while(P->i < P->number_of_philo)
    { 
        pthread_create(P->philo[P->i].th, NULL, &action, &P->philo[P->i]);
        P->i++;
    }
	while (1)
		;
    //printf("toto = %lld", toto = get_time() - P->time);
    pthread_mutex_destroy(&P->mutex);
    return (0);
}

void *action(void *arg)
{
    t_philo_i     *p;
    
    p = (t_philo_i *)arg;
	eat(p);
	dodo(p);
    printf("philo %d time = %lld \n", p->i ,get_time() - p->P->time - p->die);
    return(0);
}

void eat(t_philo_i *p)
{
	int i; 
	
	i = p->i;
	if (i == p->P->number_of_philo - 1)
		i = -1;
	i++;
	pthread_mutex_lock(&p->fork);
	pthread_mutex_lock(&p->P->philo[i].fork);
	printf("%lld ms %d has taken fork\n", get_time() - p->P->time, p->i);
	printf("%lld ms %d has taken fork to %d\n", get_time() - p->P->time, p->i, i);
	printf("%lld ms %d is eating\n", get_time() - p->P->time, p->i);
	usleep(p->P->time_to_eat);
	if (die(p) == 1)
		printf("%lld ms %d died\n", get_time() - p->P->time, p->i);
	//printf("philo = %d\n", p->i);
	//printf("philo + 1 = %d\n", i);
	printf("%lld ms %d end to eat\n", get_time() - p->P->time, p->i);
	p->die += p->P->time_to_die;
	pthread_mutex_unlock(&p->P->philo[i].fork);
	pthread_mutex_unlock(&p->fork);
}

void	dodo(t_philo_i *p)
{
	printf("%lld ms %d is sleeping\n", get_time() - p->P->time, p->i);
	usleep(p->P->time_to_sleep);
	printf("%lld ms %d is to wake up\n", get_time() - p->P->time, p->i);
}

int	die(t_philo_i *p)
{
	if (get_time() - p->P->time >= p->die)
		return (1);
	return (0); 
}