/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:48 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 09:53:13 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_STRUCTS_H
# define PHILOS_STRUCTS_H

# include <pthread.h>

typedef struct s_philo
{
	int					finished_flag;
	int					died;
	unsigned int		id;
	unsigned long		count_eating_time;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		count_time_to_eat;
	unsigned long long	contenue_time;
	unsigned long long	last_eat_time;
	pthread_t			philo;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
}				t_philo;

typedef struct s_main
{
	unsigned int	i;
	unsigned int	count_finished_philos;
	unsigned int	philo_id;
	unsigned int	fork_index;
	unsigned int	number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	count_time_to_eat;
	t_philo			*philo_x;
	pthread_mutex_t	*mtx;
}				t_main;

#endif
