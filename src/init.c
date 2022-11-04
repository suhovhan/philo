/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/04 03:00:30 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_main	args_to_struct(char **av)
{
	t_main	arg;

	arg.number_of_philo = (unsigned)ft_atoi(av[1]);
	arg.time_to_die = ft_atoi(av[2]);
	arg.time_to_eat = ft_atoi(av[3]);
	arg.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		arg.count_time_to_eat = ft_atoi(av[5]);
	return (arg);
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
		arg->philo_id++;
		arg->fork_index++;
	}
	arg->philo_x[arg->philo_id].id = arg->philo_id + 1;
	arg->philo_x[arg->philo_id].time_to_die = arg->time_to_die;
	arg->philo_x[arg->philo_id].time_to_eat = arg->time_to_eat;
	arg->philo_x[arg->philo_id].time_to_sleep = arg->time_to_sleep;
	arg->philo_x[arg->philo_id].left = &arg->mtx[arg->fork_index];
	arg->philo_x[arg->philo_id].right = &arg->mtx[0];
	return (0);
}

void	*algo_loop(void *head)
{
	t_philo				*data;
	unsigned long long	contenue_time;

	data = head;
	data->last_eat_time = gettime_milisec();
	contenue_time = gettime_milisec();
	while (1)
	{
		pthread_mutex_lock(data->left);
		printf("%llu %u has taken a left fork!🍽\n", contenue_time, data->id);
		pthread_mutex_lock(data->right);
		printf("%llu %u has taken a right fork!🍽\n", contenue_time, data->id);
		data->last_eat_time = gettime_milisec();
		printf("%llu %u is eating!🍝\n", contenue_time, data->id);
		usleep(data->time_to_eat * 1000);
		contenue_time = gettime_milisec();
		pthread_mutex_unlock(data->left);
		pthread_mutex_unlock(data->right);
		printf("%llu %u fall a sleep!🛌\n", contenue_time, data->id);
		usleep(data->time_to_sleep * 1000);
		contenue_time = gettime_milisec();
		printf("%llu %u is thinking🤔\n", contenue_time, data->id);
	}
	return (0);
}

int	simulation_loop(t_main **head)
{
	t_main	*arg;
	unsigned	i;

	arg = *head;
	while (1)
	{
		i = 0;
		while (i < arg->number_of_philo)
		{
			if (gettime_milisec() - arg->philo_x[i].last_eat_time >= arg->time_to_die)
			{
				printf("%llu %u is died!⚰️\n", arg->philo_x[i].last_eat_time, arg->philo_x[i].id);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

int	do_work(t_main *arg)
{
	unsigned int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_mutex_init(&arg->mtx[i], NULL) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (arg->philo_x[i].id % 2 != 0)
		{
			pthread_create(&arg->philo_x[i].philo, NULL, &algo_loop, &(arg->philo_x[i]));
			pthread_detach(arg->philo_x[i].philo);
		}
		i++;
	}
	usleep(50);
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (arg->philo_x[i].id % 2 == 0)
		{
			pthread_create(&arg->philo_x[i].philo, NULL, &algo_loop, &(arg->philo_x[i]));
			pthread_detach(arg->philo_x[i].philo);
		}
		i++;
	}
	simulation_loop(&arg);
	return (0);
}
