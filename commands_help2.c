/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/17 19:04:27 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstclear(t_data *data)
{
	int		i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	free(data->philos);
	free(data->fork);
}

void    ft_take_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->rfork);
    print_events(philo, take_fork);
    pthread_mutex_lock(philo->lfork);
    print_events(philo, take_fork);
}

void    ft_eat(t_philo *philo)
{
    // we need to protect this with mutex
    print_events(philo, eating);
    philo->counter++;
    philo->lmt = get_time();
    usleep(philo->all->tte * 1000);
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}

void    ft_sleep(t_philo *philo)
{
    print_events(philo, sleeping);
    usleep(philo->all->tts * 1000);
}

void    ft_think(t_philo *philo)
{
    print_events(philo, thinking);
    usleep(100 * 1000);
}