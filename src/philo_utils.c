/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:12:22 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/02 21:31:44 by ergrigor         ###   ########.fr       */
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
	int	sec;
	int	micreo_sec;
	struct timeval	fixed_time;
	struct timeval	curent_time;
	
	gettimeofday(&fixed_time, NULL);
	gettimeofday(&curent_time, NULL);
	sec = mili_sec / 1000;
	mili_sec %= 1000;
	micreo_sec = mili_sec * 1000;
	while (curent_time.tv_sec - fixed_time.tv_sec <= sec)
	{
		while (curent_time.tv_usec - fixed_time.tv_usec <= micreo_sec)
		{
			usleep(10);
			//printf("sec = %ld\tusec = %d\n", curent_time.tv_sec, curent_time.tv_usec);
			gettimeofday(&curent_time, NULL);
		}
		gettimeofday(&curent_time, NULL);
	}
	return (0);
}
