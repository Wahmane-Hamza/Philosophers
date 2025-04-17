/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/17 18:25:58 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!get_data(&data, ac, av))
			return (1);
		if (data.nop == 0 || data.nme == 0)
			return (0);
		fork_arr(&data);
		philo_arr(&data);
		if (creat_threads(&data) == 0)
			return (1);
		// start_simulation(&data, philos);
		// join_threads(&data, philos);
		// ft_lstclear(&philos, &data);
		// pthread_mutex_destroy(&data.print);
		// pthread_mutex_destroy(&data.edit);
	}
	else
	{
		write(2, "Invalid Number of Args!\n", 24);
		return (1);
	}
	return (0);
}
