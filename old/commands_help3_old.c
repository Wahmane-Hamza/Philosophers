/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help3_old.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:56:05 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 14:07:56 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	mutex_help(t_philo *philo, int flag)
// {
// 	if (flag == 0)
// 		if (!take_lfork(philo))
// 			return (0);
// 	if (flag == 1)
// 		if (!take_rfork(philo))
// 			return (0);
// 	if (flag == 2)
// 	{
// 		if (philo->flag == 0)
// 		{
// 			pthread_mutex_unlock(&philo->fork);
// 			pthread_mutex_unlock(&philo->next->fork);
// 		}
// 		else
// 		{
// 			pthread_mutex_unlock(&philo->next->fork);
// 			pthread_mutex_unlock(&philo->fork);
// 		}
// 	}
// 	return (1);
// }

// void	print_events(t_philo *philo, int flag)
// {
// 	pthread_mutex_lock(&philo->all->edit);
// 	if (philo->all->stop == 1)
// 	{
// 		pthread_mutex_unlock(&philo->all->edit);
// 		return ;
// 	}
// 	pthread_mutex_unlock(&philo->all->edit);
// 	pthread_mutex_lock(&philo->all->print);
// 	if (flag == THINKING)
// 		printf("%ld %ld is thinking\n",
// 			get_time() - philo->all->start, philo->pid);
// 	else if (flag == TAKE_FORK)
// 		printf("%ld %ld has taken a fork\n",
// 			get_time() - philo->all->start, philo->pid);
// 	else if (flag == EATING)
// 		printf("%ld %ld is eating\n",
// 			get_time() - philo->all->start, philo->pid);
// 	else if (flag == SLEEPING)
// 		printf("%ld %ld is sleeping\n",
// 			get_time() - philo->all->start, philo->pid);
// 	pthread_mutex_unlock(&philo->all->print);
// }

// void	print_death(t_philo *philo)
// {
// 	usleep(500);
// 	pthread_mutex_lock(&philo->all->print);
// 	printf("%ld %ld died\n", get_time() - philo->all->start, philo->pid);
// 	pthread_mutex_unlock(&philo->all->print);
// }


// int	take_rfork(t_philo *philo)
// {
// 	if (!check_death(philo))
// 		return (0);
// 	print_events(philo, THINKING);
// 	pthread_mutex_lock(&philo->next->fork);
// 	if (!check_death(philo))
// 		return (pthread_mutex_unlock(&philo->next->fork), 0);
// 	print_events(philo, TAKE_FORK);
// 	pthread_mutex_lock(&philo->fork);
// 	if (!check_death(philo))
// 		return (mutex_help(philo, 2), 0);
// 	print_events(philo, TAKE_FORK);
// 	print_events(philo, EATING);
// 	init_time(philo);
// 	ft_usleep(philo, philo->tte);
// 	return (1);
// }

// void	ft_lstclear(t_philo **lst, t_data *data)
// {
// 	t_philo	*tmp;
// 	int		i;

// 	i = 1;
// 	if (!lst)
// 		return ;
// 	while (i <= data->nop)
// 	{
// 		tmp = *lst;
// 		pthread_mutex_destroy(&tmp->fork);
// 		*lst = (*lst)-> next;
// 		free (tmp);
// 		i++;
// 	}
// 	tmp = NULL;
// }
