/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:07 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 11:54:48 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// t_bool check_meal(t_data *data)
// {
    
// }

t_bool check_death(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nop)
    {
        pthread_mutex_lock(&data->meal);
        if ( get_time() - data->philos[i].lmt > data->ttd)
        {
            pthread_mutex_lock(&data->stop);
            data->rip = true;
            // print_events(&data->philos[i], dead);
            pthread_mutex_unlock(&data->meal);
            pthread_mutex_unlock(&data->stop);
            return (false);
        }
        i++;
    }
    return (true);
}

void *ft_monitor(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    while (1)
    {
        pthread_mutex_lock(&data->stop);
        if (data->rip == true)
        {
            pthread_mutex_unlock(&data->stop);
            break;
        }
        pthread_mutex_unlock(&data->stop);
        if (check_death(data) == false)
            break;
        // check_meal(data)
    }
    return (NULL);
}