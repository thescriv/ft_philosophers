/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:13:55 by theo              #+#    #+#             */
/*   Updated: 2021/03/10 23:33:44 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "libft.h"

typedef struct s_philosopherInfo
{
    int number_of_philosopher;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_time_each_philosophers_must_eat;
    int is_alive;
} t_philosopher;