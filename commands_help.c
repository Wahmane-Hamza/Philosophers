/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:06:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 13:44:22 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
    t_philo *philo;

    philo = (t_philo *)arg;
    ft_wait(philo->all->start);
    while (1)
    {
        pthread_mutex_lock(&philo->all->stop);
        if (philo->all->rip == true)
        {
            pthread_mutex_unlock(&philo->all->stop);
            break;
        }
        pthread_mutex_unlock(&philo->all->stop);
        if (!ft_take_fork(philo))
            break;
        if (!ft_eat(philo))
            break; 
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}
t_bool ft_join_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nop)
    {
        pthread_join(data->philos[i].philo, NULL);
        i++;
    }
    pthread_join(data->death_note, NULL);
    return (true);
}

int creat_threads(t_data *data)
{
    int i;

    i = 0;
    data->start = get_time() + (data->nop * 20);
    while (i < data->nop)
    {
        if (pthread_create(&data->philos[i].philo, NULL, &rout, &data->philos[i]) != 0)
        {
            ft_join_threads(data);
            return (0);
        }
        i++;
    }
    if (pthread_create(&data->death_note, NULL, &ft_monitor, data) != 0)
    {
        ft_join_threads(data);
        return (0);
    }
    if (!ft_join_threads(data))
        return (0);
    return (1);
}

