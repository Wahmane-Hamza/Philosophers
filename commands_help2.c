/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 13:46:22 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstclear(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->stop);
	pthread_mutex_destroy(&data->meal);
	free(data->philos);
	free(data->fork);
}

t_bool    ft_take_fork(t_philo *philo)
{
    if ( pthread_mutex_lock(philo->rfork) != 0)
        return (false);
    print_events(philo, take_fork);
    if (pthread_mutex_lock(philo->lfork) != 0 || philo->all->nop < 2)
    {
        pthread_mutex_unlock(philo->rfork);
        return (false);
    }
    print_events(philo, take_fork);
    return (true);
}

t_bool    ft_eat(t_philo *philo)
{
    print_events(philo, eating);
    pthread_mutex_lock(&philo->all->meal);
    philo->counter++;
    philo->lmt = get_time();
    pthread_mutex_unlock(&philo->all->meal);
    ft_usleep(philo->all->tte);
    pthread_mutex_unlock(philo->lfork);
    pthread_mutex_unlock(philo->rfork); 
    return (true);
}

t_bool    ft_sleep(t_philo *philo)
{
    print_events(philo, sleeping);
    ft_usleep(philo->all->tts);
    return (true);
}

t_bool    ft_think(t_philo *philo)
{
    print_events(philo, thinking);
    ft_usleep(50);
    return (true);
}