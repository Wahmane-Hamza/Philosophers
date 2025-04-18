/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 17:09:00 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_events(t_philo *philo, int flag)
{
	if (someone_died(philo->all))
		return ;
	pthread_mutex_lock(&philo->all->print);
	if (flag == thinking)
		printf("%ld %d is thinking\n",
			get_time() - philo->all->start, philo->id);
	else if (flag == take_fork)
		printf("%ld %d has taken a fork\n",
			get_time() - philo->all->start, philo->id);
	else if (flag == eating)
		printf("%ld %d is eating\n",
			get_time() - philo->all->start, philo->id);
	else if (flag == sleeping)
		printf("%ld %d is sleeping\n",
			get_time() - philo->all->start, philo->id);
	pthread_mutex_unlock(&philo->all->print);
}

void	ft_usleep(t_data *data, time_t time)
{
	time_t	stop_time;

	stop_time = get_time() + time;
	while (get_time() < stop_time)
	{
		if (someone_died(data))
			break ;
		usleep(500);
		if (someone_died(data))
			break ;
	}
}

void	ft_wait(time_t time)
{
	while (get_time() < time)
		continue ;
}

time_t	get_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

t_bool	someone_died(t_data *data)
{
	t_bool	died;

	pthread_mutex_lock(&data->stop);
	died = data->stop_philo;
	pthread_mutex_unlock(&data->stop);
	return (died);
}
