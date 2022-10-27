/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:51 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/28 00:27:42 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H
#include "philos.structs.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int				check_ac(int ac);
int				check_wrong_arguments(char **av);
int				checker_is_nall(t_main arg, int ac);
int				checker(int ac, char **av);
int				error_and_exit();
unsigned long	ft_atoi(char *str);
void			*do_work(void *head);
int				set_mtx(t_main	*arg);
t_main 			args_to_struct(char **av);

#endif