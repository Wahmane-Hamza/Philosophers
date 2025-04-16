/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/16 16:13:07 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	init_time(philo);
	while (1)
	{
		if (!mutex_help(philo, philo->flag))
			return (NULL);
		mutex_help(philo, 2);
		if (!check_death(philo))
			return (NULL);
		pthread_mutex_lock(&philo->all->edit);
		if (philo->nme > 0)
			philo->nme--;
		if (philo->nme == 0)
			return (pthread_mutex_unlock(&philo->all->edit), NULL);
		pthread_mutex_unlock(&philo->all->edit);
		print_events(philo, SLEEPING);
		ft_usleep(philo, philo->tts);
		if (philo->nop % 2 != 0)
			usleep(900);
	}
}

int	all_done(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	pthread_mutex_lock(&philo->all->edit);
	while (1)
	{
		if (philo->nme > 0)
			return (pthread_mutex_unlock(&philo->all->edit), 1);
		philo = philo->next;
		if (philo == tmp)
			return (pthread_mutex_unlock(&philo->all->edit), 0);
	}
}

void	*check_rip(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(500);
	while (1)
	{
		pthread_mutex_lock(&philo->all->edit);
		if ((get_time() - philo->time) > philo->ttd && philo->nme)
		{
			philo->all->rip = 1;
			pthread_mutex_unlock(&philo->all->edit);
			print_death(philo);
			return (NULL);
		}
		if (philo->nme >= 0)
		{
			pthread_mutex_unlock(&philo->all->edit);
			if (!all_done(philo))
				return (NULL);
		}
		else
			pthread_mutex_unlock(&philo->all->edit);
		philo = philo->next;
	}
}

void	start_simulation(t_data *data, t_philo *philos)
{
	int		i;
	t_philo	*current_philo;

	i = 1;
	data->start = get_time();
	current_philo = philos;
	while (i <= data->nop)
	{
		pthread_create(&current_philo->philo, NULL, &routine,
			(void *)current_philo);
		current_philo = current_philo->next;
		i++;
	}
	pthread_create(&data->philos, NULL, &check_rip, (void *)current_philo);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	philos = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!get_data(&data, ac, av))
			return (1);
		if (data.nop == 0 || data.nme == 0)
			return (0);
		creat_list(&data, &philos);
		start_simulation(&data, philos);
		join_threads(&data, philos);
		ft_lstclear(&philos, &data);
		pthread_mutex_destroy(&data.print);
		pthread_mutex_destroy(&data.edit);
	}
	else
	{
		write(2, "Invalid Number of Args!\n", 24);
		return (1);
	}
	return (0);
}
