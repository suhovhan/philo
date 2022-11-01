/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:12:22 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/31 19:40:13 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_atoi(char *str)
{
	unsigned long	res;
	int				i;

	res = 0;
	i = -1;
	while (str[++i])
	{
		res *= 10;
		res += str[i] - '0';
	}
	return (res);
}

int	ft_msleep(int mili_sec)
{
	struct	timeval	fixed_time;
	struct	timeval	curent_time;
	int				sec;

	mili_sec -= 1;
	gettimeofday(&fixed_time, NULL);
	gettimeofday(&curent_time, NULL);
	sec = mili_sec / 1000;
	mili_sec %= 1000;
	while(curent_time.tv_sec - fixed_time.tv_sec <= sec || \
	curent_time.tv_usec - fixed_time.tv_usec < mili_sec)
	{
		usleep(100);
		gettimeofday(&curent_time, NULL);
	}
	return (0);
}
