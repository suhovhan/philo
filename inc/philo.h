/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:51 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 06:08:47 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H
#include "philos.structs.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>

void			ft_putstr(char *str);
void			print_header();
int				check_ac(int ac);
int				check_wrong_arguments(char **av);
int				checker_is_nall(t_main arg, int ac);
int				checker(int ac, char **av);
int				error_and_exit();
int				do_work(t_main *arg);
unsigned long long	gettime_milisec(void);
int				ft_msleep(int mili_sec);
int				set_mtx(t_main	*arg);
unsigned long	ft_atoi(char *str);
void			*algo_loop(void *head);
int				simulation_loop(t_main **head);
t_main 			args_to_struct(char **av);

#endif