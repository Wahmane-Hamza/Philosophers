/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 16:56:03 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool someone_died(t_data *data)
{
    t_bool died;

    pthread_mutex_lock(&data->stop);
    died = data->stop_philo;
    pthread_mutex_unlock(&data->stop);
    return died;
}


void	ft_lstclear(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->stop);
	pthread_mutex_destroy(&data->meal);
    int i;
    i = 0;
    while (i < data->nop)
    {
        pthread_mutex_destroy(&data->fork[i]);
        i++;
    }
	free(data->philos);
	free(data->fork);
}

t_bool ft_take_fork(t_philo *philo)
{
    if (someone_died(philo->all))
        return (false);
    if (pthread_mutex_lock(philo->rfork) != 0)
        return (false);
    if (someone_died(philo->all))
    {
        pthread_mutex_unlock(philo->rfork);
        return (false);
    }
    print_events(philo, take_fork);
    
    if (philo->all->nop < 2 || pthread_mutex_lock(philo->lfork) != 0)
    {
        pthread_mutex_unlock(philo->rfork);
        return (false);
    }
    if (someone_died(philo->all))
    {
        pthread_mutex_unlock(philo->lfork);
        pthread_mutex_unlock(philo->rfork);
        return (false);
    }
    print_events(philo, take_fork);
    return (true);
}

t_bool ft_eat(t_philo *philo)
{
    if (someone_died(philo->all))
    {
        pthread_mutex_unlock(philo->lfork);
        pthread_mutex_unlock(philo->rfork);
        return (false);
    }
    print_events(philo, eating);
    pthread_mutex_lock(&philo->all->meal);
    philo->counter++;
    philo->lmt = get_time();
    pthread_mutex_unlock(&philo->all->meal);
    ft_usleep(philo->all, philo->all->tte);
    pthread_mutex_unlock(philo->lfork);
    pthread_mutex_unlock(philo->rfork);
    if (philo->all->nme != -10 && philo->counter == philo->all->nme)
        return (false);
    return (true);
}

t_bool ft_sleep(t_philo *philo)
{
    if (someone_died(philo->all))
        return (false);
    print_events(philo, sleeping);
    ft_usleep(philo->all, philo->all->tts);
    return (true);
}

t_bool ft_think(t_philo *philo)
{
    time_t ttt;

    if (someone_died(philo->all))
        return (false);
    pthread_mutex_lock(&philo->all->meal);
    ttt = (philo->all->ttd -  (get_time() - philo->lmt)) / 2;
    pthread_mutex_unlock(&philo->all->meal);
    if (ttt <= 0)
        ttt = 0;
    else if (ttt > 200)
        ttt = 200;
    print_events(philo, thinking);
    ft_usleep(philo->all, ttt);
    return (true);
}
