/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/12/14 17:34:50 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_to_struct(t_main *arg, char **av)
{
	arg->number_of_philo = (unsigned)ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		arg->count_time_to_eat = ft_atoi(av[5]);
	else
		arg->count_time_to_eat = 0;
	return (0);
}

int	set_mtx(t_main	*arg)
{
	arg->philo_id = 0;
	arg->fork_index = 0;
	while (arg->philo_id + 1 < arg->number_of_philo)
	{
		arg->philo_x[arg->philo_id].id = arg->philo_id + 1;
		arg->philo_x[arg->philo_id].left = &arg->mtx[arg->fork_index];
		arg->philo_x[arg->philo_id].right = &arg->mtx[arg->fork_index + 1];
		arg->philo_x[arg->philo_id].time_to_die = arg->time_to_die;
		arg->philo_x[arg->philo_id].time_to_eat = arg->time_to_eat;
		arg->philo_x[arg->philo_id].time_to_sleep = arg->time_to_sleep;
		arg->philo_x[arg->philo_id].count_time_to_eat = arg->count_time_to_eat;
		arg->philo_id++;
		arg->fork_index++;
	}
	arg->philo_x[arg->philo_id].id = arg->philo_id + 1;
	arg->philo_x[arg->philo_id].left = &arg->mtx[arg->fork_index];
	arg->philo_x[arg->philo_id].right = &arg->mtx[0];
	arg->philo_x[arg->philo_id].time_to_die = arg->time_to_die;
	arg->philo_x[arg->philo_id].time_to_eat = arg->time_to_eat;
	arg->philo_x[arg->philo_id].time_to_sleep = arg->time_to_sleep;
	arg->philo_x[arg->philo_id].count_time_to_eat = arg->count_time_to_eat;
	return (0);
}

void	*routine(void *head)
{
	t_philo				*data;

	data = head;
	data->count_eating_time = 0;
	data->contenue_time = gettime_milisec();
	data->last_eat_time = gettime_milisec();
	data->finished_flag = 0;
	if (data->id % 2 == 0)
		usleep(50);
	algo_loop(&data);
	return (0);
}

int	do_work(t_main *arg)
{
	unsigned int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_init(&arg->mtx[i], NULL);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_create(&(arg->philo_x[i].philo), \
				NULL, &routine, &(arg->philo_x[i]));
		pthread_detach(arg->philo_x[i].philo);
		i++;
	}
	usleep(100);
	simulation_loop(&arg);
	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&arg->mtx[i]);
		i++;
	}
	return (0);
}
