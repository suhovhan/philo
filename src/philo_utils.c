/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:12:22 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 07:12:57 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

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

unsigned long long	gettime_milisec(void)
{
	struct timeval		curent_time;
	unsigned long long	tv_msec;

	gettimeofday(&curent_time, NULL);
	tv_msec = curent_time.tv_sec * 1000 + curent_time.tv_usec / 1000;
	return (tv_msec);
}

int	ft_msleep(int time)
{
	unsigned long long	fixed_tv_msec;
	unsigned long long	curent_tv_msec;
	unsigned long long	mili_sec;

	mili_sec = time;
	fixed_tv_msec = gettime_milisec();
	curent_tv_msec = gettime_milisec();
	while (curent_tv_msec - fixed_tv_msec < mili_sec)
	{
		usleep(10);
		curent_tv_msec = gettime_milisec();
	}
	return (0);
}
