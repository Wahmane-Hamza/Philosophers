/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:32:36 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/12 17:30:54 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_str(char *str)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (str[o] == '0')
		o++;
	while (str[i] != '\0')
		i++;
	if (i - o > 19)
		return (-1);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (ft_check_str(str) == -1)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	if (result < 0)
		return (-1);
	return (result);
}

int	get_data(t_data *data, int ac, char **av)
{
	data->i = 1;
	data->nop = ft_atol(av[1]);
	data->ttd = ft_atol(av[2]);
	data->tte = ft_atol(av[3]);
	data->tts = ft_atol(av[4]);
	if (ac == 6)
		data->nme = ft_atol(av[5]);
	if (data->nme == -1 || data->nop == -1 || data->ttd == -1 || data->tte == -1
		|| data->tts == -1)
	{
		write(2, "Invalid Input!\n", 15);
		return (0);
	}
	return (1);
}
