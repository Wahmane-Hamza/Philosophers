/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:06:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/17 18:36:27 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void philo_arr(t_data *data)
{
    int i;

    data->philos = malloc(data->nop * sizeof(t_philo));
    i = 0;
    while (i < data->nop)
    {
        data->philos[i].id = i + 1;
        data->philos[i].lmt = get_time();
        data->philos[i].counter = 0;
        data->philos[i].all = data;
        if (i % 2 == 0)
        {
            data->philos[i].rfork = &data->fork[i];
            data->philos[i].lfork = &data->fork[(i + 1) % data->nop];
        }
        else
        {
            data->philos[i].rfork = &data->fork[(i + 1) % data->nop];
            data->philos[i].lfork = &data->fork[i];
        }
        i++;
    }
}

void fork_arr(t_data *data)
{
    int i;

    data->fork = malloc(data->nop * sizeof(pthread_mutex_t));
    i = 0;
    while (i < data->nop)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
}

void *rout(void *arg)
{
    
    


    return (NULL);
}

int creat_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nop)
    {
        
        if (pthread_create(&data->philos[i].philo, NULL, &rout, &data->philos[i]) != 0)
        {
            ft_lstclear(data);
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < data->nop)
    {
        if (pthread_join(data->philos[i].philo, NULL) != 0)
        {
            ft_lstclear(data);
            return (0);
        }
    }
    return (1);
}

