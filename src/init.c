/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/27 22:31:37 by suhovhan         ###   ########.fr       */
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
		arg->philo_x[arg->philo_id].left = arg->mtx[arg->fork_index];
		arg->philo_x[arg->philo_id].right = arg->mtx[arg->fork_index + 1];
		arg->philo_id++;
		arg->fork_index++;
	}
	// arg->philo_x[arg->philo_id].number_of_philo = arg->number_of_philo;
	arg->philo_x[arg->philo_id].id = arg->philo_id + 1;
	arg->philo_x[arg->philo_id].time_to_die = arg->time_to_die;
	arg->philo_x[arg->philo_id].time_to_eat = arg->time_to_eat;
	arg->philo_x[arg->philo_id].time_to_die = arg->time_to_sleep;
	arg->philo_x[arg->philo_id].left = arg->mtx[arg->fork_index];
	arg->philo_x[arg->philo_id].right = arg->mtx[0];
	return (0);
}

int	algo_loop(t_philo data)
{
	unsigned long	hungry_time_milisec;
	struct	timeval	curent_time;
	
	if (pthread_mutex_init(&data.left, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data.right, NULL) != 0)
		return (-1);
	gettimeofday(&curent_time, NULL);
	hungry_time_milisec = curent_time.tv_usec / 1000;
	while (1)
	{
		if (hungry_time_milisec == data.time_to_die)
		{
			printf("philo is died\n");
			return (0);
		}
		pthread_mutex_lock(&data.left);
		if (hungry_time_milisec == data.time_to_die)
		{
			printf("philo is died\n");
			return (0);
		}
		printf("philo has taken a fork!\n");
		pthread_mutex_lock(&data.right);
		if (hungry_time_milisec == data.time_to_die)
		{
			printf("philo is died\n");
			return (0);
		}
		printf("philo has taken a fork!\n");
		printf("philo is eating!\n");
		usleep(data.time_to_eat);
		gettimeofday(&curent_time, NULL);
		hungry_time_milisec = curent_time.tv_usec / 1000;	
		pthread_mutex_unlock(&data.left);
		pthread_mutex_unlock(&data.right);
		printf("philo fall a sleep!\n");
		usleep(data.time_to_sleep);
		if (hungry_time_milisec == data.time_to_die)
		{
			printf("philo is died\n");
			return (0);
		}
		printf("philo is thinking");
	}
	return (0);
}

// void	*do_work(void *head)
// {
// 	t_main	*arg;
// 	arg = head;

// }
