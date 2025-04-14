/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:37:25 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/14 16:50:00 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define THINKING 5
# define TAKE_FORK 6
# define EATING 7
# define SLEEPING 8
# define DEAD 9

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		philo;
	int				flag;
	long			time;
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
	pthread_t		philos;
	long			start;
	long			i;
	long			nop;
	long			ttd;
	long			tte;
	long			tts;
	long			nme;
	long			rip;
	pthread_mutex_t	edit;
	pthread_mutex_t	print;
}					t_data;

int					get_data(t_data *data, int ac, char **av);
void				creat_list(t_data *data, t_philo **philos);
void	init_time(t_philo *philo);
void	ft_usleep(t_philo *philo, long t);
long	get_time(void);
t_philo	*lst_last(t_philo *head);
t_philo	*new_node(t_data *data);
void	lst_add_back(t_philo **head, t_philo *new_node);
int	take_lfork(t_philo *philo);
int	check_death(t_philo *philo);
void	print_events(t_philo *philo, int flag);
int	mutex_help(t_philo *philo, int flag);
void	print_death(t_philo *philo);
void	join_threads(t_data *data, t_philo *philos);
int	take_fork(t_philo *philo);
void	ft_lstclear(t_philo **lst, t_data *data);

#endif