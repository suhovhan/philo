/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 05:25:14 by suhovhan         ###   ########.fr       */
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
    else
        arg.count_time_to_eat = 0;
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

void	*algo_loop(void *head)
{
	t_philo				*data;
	unsigned long long	contenue_time;
    unsigned long    count_eating_time;

    count_eating_time = 0;
	data = head;
	contenue_time = gettime_milisec();
	data->last_eat_time = gettime_milisec();
    data->finished_flag = 0;
	if (data->id % 2 == 0)
		usleep(50);
	while (1)
	{
		pthread_mutex_lock(data->left);
		printf("%llu %u has taken a left fork\n", contenue_time, data->id);
		pthread_mutex_lock(data->right);
		printf("%llu %u has taken a right fork\n", contenue_time, data->id);
		data->last_eat_time = gettime_milisec();
		printf("%llu %u is eating\n", contenue_time, data->id);
		ft_msleep(data->time_to_eat);
		pthread_mutex_unlock(data->left);
		pthread_mutex_unlock(data->right);
		contenue_time = gettime_milisec();
        count_eating_time++;
		if (count_eating_time == data->count_time_to_eat)
		{
			printf("%llu %u philo has finished simulation\n", contenue_time, data->id);
			data->finished_flag++;
			return (0);
		}
		printf("%llu %u fall a sleep\n", contenue_time, data->id);
		ft_msleep(data->time_to_sleep);
		contenue_time = gettime_milisec();
		printf("%llu %u is thinking\n", contenue_time, data->id);
	}
	return (0);
}

int	simulation_loop(t_main **head)
{
	t_main	*arg;
	unsigned	i;
    unsigned	count_finished_philos;

    count_finished_philos = 0;
	arg = *head;
	while (1)
	{
        i = 0;
		while (i < arg->number_of_philo)
		{
			if (count_finished_philos == arg->number_of_philo)
				return (1);
			if (gettime_milisec() - arg->philo_x[i].last_eat_time >= arg->time_to_die \
				&& arg->philo_x[i].finished_flag == 0)
			{
				printf("%llu %u is died\n", arg->philo_x[i].last_eat_time, arg->philo_x[i].id);
				return (-1);
			}
			if (arg->philo_x[i].finished_flag == 1)
			{
				arg->philo_x[i].finished_flag++;
				count_finished_philos++;
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
		pthread_create(&arg->philo_x[i].philo, NULL, &algo_loop, &(arg->philo_x[i]));
		pthread_detach(arg->philo_x[i].philo);
		i++;
	}
	simulation_loop(&arg);
	return (0);
}
