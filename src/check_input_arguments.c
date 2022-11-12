/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:55 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 12:03:15 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ac(int ac)
{
	if (ac == 5 || ac == 6)
		return (1);
	return (0);
}

int	check_wrong_arguments(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	}
	return (1);
}

int	checker(int ac, char **av)
{
	if (!check_ac(ac))
	{
		write(2, "Error: something is wrong!\n", 27);
		return (-1);
	}
	if (!check_wrong_arguments(av))
	{
		write(2, "Error: something is wrong!\n", 27);
		return (-1);
	}
	return (0);
}

int	checker_is_nall(t_main arg, int ac)
{
	if (arg.number_of_philo <= 0 \
		|| arg.time_to_die <= 0 \
		|| arg.time_to_eat <= 0 \
		|| arg.time_to_sleep <= 0)
		return (-1);
	if (ac == 6 && arg.count_time_to_eat <= 0)
	{
		write(2, "Error: something is wrong!\n", 27);
		return (-1);
	}
	return (0);
}
