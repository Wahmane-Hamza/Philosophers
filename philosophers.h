/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:37:25 by hwahmane          #+#    #+#             */
/*   Updated: 2025/04/18 15:57:26 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>


typedef enum s_status
{
	thinking,
	take_fork,
	eating,
	sleeping,
	dead,
}	t_status;

typedef enum s_bool
{
	false,
	true,
}	t_bool;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				counter;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	time_t			lmt;
	struct s_data	*all;
}					t_philo;

typedef struct s_data
{
	pthread_t		death_note;
	t_philo			*philos;
	pthread_mutex_t	*fork;
	time_t			start;
	int				nop;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	int				nme;
	t_bool			stop_philo;
	pthread_mutex_t	meal;
	pthread_mutex_t	print;
	pthread_mutex_t	stop;
}					t_data;

// Parsing
int					get_data(t_data *data, int ac, char **av);

// Command_help
int creat_threads(t_data *data);
void fork_arr(t_data *data);
void philo_arr(t_data *data);
void *rout(void *arg);
t_bool ft_join_threads(t_data *data);

// Command_help2
t_bool someone_died(t_data *data);
void	ft_lstclear(t_data *data);
t_bool    ft_take_fork(t_philo *philo);
t_bool    ft_eat(t_philo *philo);
t_bool    ft_sleep(t_philo *philo);
t_bool    ft_think(t_philo *philo);

// Command_help3
void	print_events(t_philo *philo, int flag);
void ft_usleep(t_data *data, time_t time);
void ft_wait(time_t time);
long	get_time(void);

// Command_help4
void *ft_monitor(void *arg);










// void				creat_list(t_data *data, t_philo **philos);
// void	init_time(t_philo *philo);
// void	ft_usleep(t_philo *philo, long t);
// t_philo	*lst_last(t_philo *head);
// t_philo	*new_node(t_data *data);
// void	lst_add_back(t_philo **head, t_philo *new_node);
// int	take_lfork(t_philo *philo);
// int	check_death(t_philo *philo);
// void	print_events(t_philo *philo, int flag);
// int	mutex_help(t_philo *philo, int flag);
// void	print_death(t_philo *philo);
// void	join_threads(t_data *data, t_philo *philos);
// int	take_rfork(t_philo *philo);
// void	ft_lstclear(t_philo **lst, t_data *data);

#endif