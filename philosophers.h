/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:37:25 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/13 15:19:47 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	fork;
	// pthread_t		philo;
	int				flag;
	// long			time;
	long			pid;
	long			ttd;
	long			tte;
	long			tts;
	long			nme;
	long			nop;
	struct s_data	*all;
	struct s_philo	*next;
}					t_philo;

typedef struct s_data
{
	t_philo			*first_filo;
	// pthread_t		philos;
	long			i;
	long			nop;
	long			ttd;
	long			tte;
	long			tts;
	long			nme;
}					t_data;

int					get_data(t_data *data, int ac, char **av);
void				creat_list(t_data *data, t_philo **philos);

#endif