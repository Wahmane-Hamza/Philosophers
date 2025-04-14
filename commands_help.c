/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:58:06 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/14 16:47:12 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*lst_last(t_philo *head)
{
	if (!head)
		return (NULL);
	while (head && head->next)
		head = head->next;
	return (head);
}

t_philo	*new_node(t_data *data)
{
	t_philo	*new_node;

	new_node = malloc(sizeof(t_philo));
	if (data->i == 1)
		data->first_filo = new_node;
	pthread_mutex_init(&new_node->fork, NULL);
	new_node->all = data;
	new_node->tte = data->tte;
	new_node->ttd = data->ttd;
	new_node->tts = data->tts;
	new_node->nme = data->nme;
	new_node->nop = data->nop;
	new_node->pid = data->i;
	if (data->i % 2 == 0)
		new_node->flag = 1;
	else
		new_node->flag = 0;
	if (data->i == data->nop)
		new_node->next = data->first_filo;
	else
		new_node->next = NULL;
	return (new_node);
}

void	lst_add_back(t_philo **head, t_philo *new_node)
{
	t_philo	*last_node;

	if (!head)
		return ;
	last_node = lst_last(*head);
	if (*head)
		last_node->next = new_node;
	else
		*head = new_node;
}

void	creat_list(t_data *data, t_philo **philos)
{
	while (data->i <= data->nop)
	{
		lst_add_back(philos, new_node(data));
		data->i++;
	}
}

void	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 1;
	while (i <= data->nop)
	{
		pthread_join(philos->philo, NULL);
		philos = philos->next;
		i++;
	}
	pthread_join(data->philos, NULL);
}
