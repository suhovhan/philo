/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:48 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/02 19:11:38 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

#include <pthread.h>

typedef struct s_philo
{
	int				died;
	unsigned		id;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	count_time_to_eat;
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_philo;

typedef	struct s_main
{
	unsigned		philo_id;
	unsigned		fork_index;
	unsigned 		number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	count_time_to_eat;
	t_philo			*philo_x;
	pthread_mutex_t *mtx;
}				t_main;

#endif