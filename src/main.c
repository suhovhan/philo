/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:49:01 by suhovhan          #+#    #+#             */
/*   Updated: 2022/12/14 17:35:31 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{	
	t_main			arg;
	t_philo			*data;
	unsigned int	i;

	i = 0;
	print_header();
	if (checker(ac, av))
		return (-1);
	args_to_struct(&arg, av);
	if (checker_is_nall(arg, ac) != 0)
		return (-1);
	data = malloc(sizeof(t_philo) * arg.number_of_philo);
	arg.mtx = malloc(sizeof(pthread_mutex_t) * arg.number_of_philo);
	if (ac == 6)
		data->count_time_to_eat = arg.count_time_to_eat;
	else
		data->count_time_to_eat = 0;
	arg.philo_x = data;
	set_mtx(&arg);
	do_work(&arg);
	free(data);
	free(arg.mtx);
	return (0);
}
