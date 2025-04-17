/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/17 18:23:50 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstclear(t_data *data)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	free(data->philos);
	free(data->fork);
}

void    ft_take_fork(t_data *data)
{
    
}

void    ft_eat(t_data *data)
{
    
}

void    ft_sleep(t_data *data)
{
    
}

void    ft_think(t_data *data)
{
    
}