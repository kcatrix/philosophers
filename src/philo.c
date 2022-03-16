/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:30:28 by operculesan       #+#    #+#             */
/*   Updated: 2022/03/16 18:02:17 by operculesan      ###   ########.fr       */
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
    long long toto;

    //if (parse(argc, argv) != 0)
    //    return(parse(argc, argv));
    init_struct(argc, argv, P);
    pthread_t th[P->number_of_philo];
    pthread_mutex_init(&P->mutex, NULL);
    while(P->i != P->number_of_philo)
        pthread_create(&th[P->i++], NULL, &action, P);
    P->i = 0;
    //printf("toto = %lld", toto = get_time() - P->time);
    while(P->i != P->number_of_philo)
        pthread_join(th[P->i++], NULL);
    pthread_mutex_destroy(&P->mutex);
    return 0;
}

void *action(void *arg)
{
    t_philo     *P;
    
    P = (t_philo *)arg;
    pthread_mutex_lock(&P->mutex);
    printf("time = %lld philo = %d\n", get_time() - P->time, P->i);
    pthread_mutex_unlock(&P->mutex);
    
}


