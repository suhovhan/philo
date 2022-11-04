/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:49:01 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/04 01:46:17 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{	
	t_main		arg;
	t_philo		*data;
	unsigned	i;

	i = 0;
	if (checker(ac, av))
	{
		write(2, "Error: something is wrong!\n", 27);
		return (0);
	}
	arg = args_to_struct(av);
	if (checker_is_nall(arg, ac) != 0)
	{
		write(2, "Error: something is wrong!\n", 27);
		return (0);
	}
	data = malloc(sizeof(t_philo) * arg.number_of_philo);
	arg.mtx = malloc(sizeof(pthread_mutex_t) * arg.number_of_philo);
	if (!data || !arg.mtx)
	{
		printf("Error: can't allocate memory\n");
		return (0);
	}
	if (ac == 6)
		data->count_time_to_eat = arg.count_time_to_eat;
	else
		data->count_time_to_eat = 0;
	arg.philo_x = data;
	set_mtx(&arg);
	do_work(&arg);
	free(arg.philo_x);
	free(arg.mtx);
	return (0);
}