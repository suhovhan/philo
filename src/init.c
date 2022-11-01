/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/31 20:23:35 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	data = head;
	gettimeofday(&curent_time, NULL);
	hungry_time = curent_time.tv_usec / 1000;
	usleep(10);
	while (1)
	{
		gettimeofday(&curent_time, NULL);
		if (curent_time.tv_usec / 1000 - hungry_time >= data->time_to_die)
		{
			printf("%ld %u is died!!!!!!\n",curent_time.tv_sec, data->id);
			break;
		}
		pthread_mutex_lock(data->left);
		printf("%ld %u has taken a fork!\n",curent_time.tv_sec, data->id);
		gettimeofday(&curent_time, NULL);
		if (curent_time.tv_usec / 1000 - hungry_time >= data->time_to_die)
		{
			printf("%ld %u is died!!!!!!\n",curent_time.tv_sec, data->id);
			break;
		}
		pthread_mutex_lock(data->right);
		printf("%ld %u has taken a fork!\n", curent_time.tv_sec, data->id);
		printf("%ld %u is eating!\n", curent_time.tv_sec, data->id);
		ft_msleep(data->time_to_eat);
		gettimeofday(&curent_time, NULL);
		hungry_time = curent_time.tv_usec / 1000;
		pthread_mutex_unlock(data->left);
		pthread_mutex_unlock(data->right);
		printf("%ld %u fall a sleep!\n", curent_time.tv_sec, data->id);
		ft_msleep(data->time_to_sleep);
		gettimeofday(&curent_time, NULL);
		printf("%ld %u is thinking\n", curent_time.tv_sec, data->id);
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
			pthread_create(&arg->philo_x[i].philo, NULL, algo_loop, &arg->philo_x[i]);
		i++;
	}
	usleep(50);
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (arg->philo_x[i].id % 2 == 0)
			pthread_create(&arg->philo_x[i].philo, NULL, algo_loop, &arg->philo_x[i]);
			pthread_join(arg->philo_x[i].philo, NULL);
		i++;
	}
	// i = 0;
	// while (i < arg->number_of_philo)
	// {
	// 	pthread_detach(arg->philo_x[i].philo);
	// 	i++;
	// }
	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&arg->mtx[i]);
		i++;
	}
	return (0);
}
