/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:07 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 16:58:31 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool check_meal(t_data *data)
{
    int i;
    int stop;

    i = 0;
    stop = 1;
    pthread_mutex_lock(&data->meal);
    while (i < data->nop)
    {
        if (data->philos[i].counter != data->nme)
        {
            stop = 0;            
            break;
        }
        i++;
    }
    if (stop == 1)
    {
        pthread_mutex_lock(&data->stop);
        data->stop_philo = true;
        pthread_mutex_unlock(&data->meal);
        pthread_mutex_unlock(&data->stop);
        return (false);
    }
    pthread_mutex_unlock(&data->meal);
    return (true);
}

t_bool check_death(t_data *data)
{
    int i;

    i = 0;
    pthread_mutex_lock(&data->meal);
    while (i < data->nop)
    {
        if ( get_time() - data->philos[i].lmt > data->ttd)
        {
            pthread_mutex_lock(&data->stop);
            data->stop_philo = true;
            pthread_mutex_unlock(&data->meal);
        	pthread_mutex_lock(&data->print);
            printf("%ld %d is dead\n",
			    get_time() - data->start, data->philos[i].id);
            pthread_mutex_unlock(&data->print);
            pthread_mutex_unlock(&data->stop);
            return (false);
        }
        i++;
    }
    pthread_mutex_unlock(&data->meal);
    return (true);
}

void *ft_monitor(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    ft_wait(data->start);
    while (1)
    {
        usleep(500);
        pthread_mutex_lock(&data->stop);
        if (data->stop_philo == true)
        {
            pthread_mutex_unlock(&data->stop);
            break;
        }
        pthread_mutex_unlock(&data->stop);
        if (data->nme != -10)
        {
            if (check_meal(data) == false)
                break;
        }
        if (check_death(data) == false)
            break;
    }
    return (NULL);
}
