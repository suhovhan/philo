/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/01 22:13:31 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_died(t_philo *data)
{
	while (1)
	{
		if ()
			return (-1);
	}
}

t_main args_to_struct(char **av)
{
	t_main arg;

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
	// arg->philo_x[arg->philo_id].number_of_philo = arg->number_of_philo;
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
	t_philo 		*data;
	struct			timeval	curent_time;
	unsigned 		hungry_time;
	unsigned long	contenue_time;

	data = head;
	contenue_time = 0;
	gettimeofday(&curent_time, NULL);
	hungry_time = curent_time.tv_usec / 1000;
	// usleep(10);
	while (1)
	{
		gettimeofday(&curent_time, NULL);
		if (curent_time.tv_usec / 1000 - hungry_time >= data->time_to_die)
		{
			printf("%lu %u is died!!!!!!\n", contenue_time, data->id);
			break;
		}
		pthread_mutex_lock(data->left);
		printf("%lu %u has taken a fork!\n", contenue_time, data->id);
		gettimeofday(&curent_time, NULL);
		if (curent_time.tv_usec / 1000 - hungry_time >= data->time_to_die)
		{
			printf("%lu %u is died!!!!!!\n", contenue_time, data->id);
			break;
		}
		pthread_mutex_lock(data->right);
		printf("%lu %u has taken a fork!\n", contenue_time, data->id);
		printf("%lu %u is eating!\n", contenue_time, data->id);
		ft_msleep(data->time_to_eat);
		contenue_time += data->time_to_eat;
		gettimeofday(&curent_time, NULL);
		hungry_time = curent_time.tv_usec / 1000;
		pthread_mutex_unlock(data->left);
		pthread_mutex_unlock(data->right);
		printf("%lu %u fall a sleep!\n", contenue_time, data->id);
		ft_msleep(data->time_to_sleep);
		contenue_time += data->time_to_sleep;
		gettimeofday(&curent_time, NULL);
		printf("%lu %u is thinking\n", contenue_time, data->id);
	}
	return (0);
}

int	do_work(t_main *arg)
{
	unsigned	i = 0;

	while (i < arg->number_of_philo)
	{
		if (pthread_mutex_init(&arg->mtx[i], NULL) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (arg->philo_x[i].id % 2)
		{
			pthread_create(&arg->philo_x[i].philo, NULL, algo_loop, &arg->philo_x[i]);
			pthread_detach(arg->philo_x[i].philo);
		}
		i++;
	}
	usleep(100);
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (arg->philo_x[i].id % 2 == 0)
		{
			pthread_create(&arg->philo_x[i].philo, NULL, algo_loop, &arg->philo_x[i]);
			pthread_detach(arg->philo_x[i].philo);
		}
		i++;
	}
	return (0);
}
