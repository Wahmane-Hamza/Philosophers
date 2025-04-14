/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:34 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/14 14:55:35 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->edit);
	philo->time = get_time();
	pthread_mutex_unlock(&philo->all->edit);
}

void	ft_usleep(t_philo *philo, long t)
{
	long	time;

	time = get_time();
	while (get_time() - time < t)
	{
		pthread_mutex_lock(&philo->all->edit);
		if (philo->all->rip == 1)
		{
			pthread_mutex_unlock(&philo->all->edit);
			break ;
		}
		pthread_mutex_unlock(&philo->all->edit);
		usleep(500);
	}
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->edit);
	if (philo->all->rip == 1)
	{
		pthread_mutex_unlock(&philo->all->edit);
		return (0);
	}
	pthread_mutex_unlock(&philo->all->edit);
	return (1);
}

int	take_lfork(t_philo *philo)
{
	if (!check_death(philo))
		return (0);
	print_events(philo, THINKING);
	pthread_mutex_lock(&philo->fork);
	if (!check_death(philo))
		return (pthread_mutex_unlock(&philo->fork), 0);
	print_events(philo, TAKE_FORK);
	if (philo->all->nop == 1)
	{
		pthread_mutex_unlock(&philo->fork);
		return (ft_usleep(philo, philo->ttd), 0);
	}
	pthread_mutex_lock(&philo->next->fork);
	if (!check_death(philo))
		return (mutex_help(philo, 2), 0);
	print_events(philo, TAKE_FORK);
	print_events(philo, EATING);
	init_time(philo);
	ft_usleep(philo, philo->tte);
	return (1);
}
