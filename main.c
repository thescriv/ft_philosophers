/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:16:31 by theo              #+#    #+#             */
/*   Updated: 2021/03/10 23:37:01 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//Done the part of creating thread and wait them to die.
//Now need the part of the philosophers logic

void fill_philo_information(t_philosopher *philoStruct, char **av, int optionalParam)
{
    philoStruct->number_of_philosopher = ft_atoi(av[1]);
    philoStruct->time_to_die = ft_atoi(av[2]);
    philoStruct->time_to_eat = ft_atoi(av[3]);
    philoStruct->time_to_sleep = ft_atoi(av[4]);
    philoStruct->is_alive = 1;
    philoStruct->number_of_time_each_philosophers_must_eat = -1;

    if (optionalParam)
    {
        philoStruct->number_of_time_each_philosophers_must_eat = ft_atoi(av[5]);
    }
}

void philoLoop(void **philoParams)
{
    t_philosopher *philoInfo;
    int i = 0;

    philoInfo = (t_philosopher *)philoParams;

    printf("\n%d %d %d %d\n",
           philoInfo->number_of_philosopher,
           philoInfo->time_to_die,
           philoInfo->time_to_eat,
           philoInfo->time_to_sleep);

    while (philoInfo->is_alive)
    {
        if (i == 256)
        {
            printf("I'm dead bye");
        }

        if (i == 1500) {
            philoInfo->is_alive = 0;
        }
        i++;
    }

    //return NULL;
}

void create_philosophers(t_philosopher *philoStruct)
{
    int i;
    pthread_t philos[philoStruct->number_of_philosopher];

    i = -1;

    while (++i < philoStruct->number_of_philosopher)
    {
        if (pthread_create(&philos[i], NULL, (void *)philoLoop, philoStruct))
        {
            printf("Error while creating thread");
        }
    }

    i = -1;

    while (++i < philoStruct->number_of_philosopher)
    {
        if (pthread_join(philos[i], NULL))
        {
            printf("Error while creating thread");
        }
    }
}

void start(t_philosopher *philoStruct, char **av, int optionalParam)
{
    fill_philo_information(philoStruct, av, optionalParam);

    create_philosophers(philoStruct);
}

int main(int ac, char **av)
{
    t_philosopher philoStruct;
    int optionalParam;

    if (ac < 4 || ac > 5)
    {
        ft_putstr("Sorry not Sorry");
    }

    optionalParam = ac == 5;

    start(&philoStruct, av, optionalParam);

    return (0);
}