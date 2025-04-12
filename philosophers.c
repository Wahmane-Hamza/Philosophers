/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/12 18:20:56 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	}
	else
	{
		write(2, "Invalid Number of Args!\n", 24);
		return (1);
	}
	return (0);
}
