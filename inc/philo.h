/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:48:51 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/03 21:00:58 by ergrigor         ###   ########.fr       */
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
int				do_work(t_main *arg);
unsigned long long	gettime_milisec(void);
int				ft_msleep(int mili_sec);
int				set_mtx(t_main	*arg);
unsigned long	ft_atoi(char *str);
void			*algo_loop(void *head);
int				simulation_loop(t_main **head);
t_main 			args_to_struct(char **av);

// ........ft_printf_utils........

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned long long nbr);
void	ft_printf(char *str, ...);

// ........ft_printf_utils........

#endif