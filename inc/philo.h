/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:35:59 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/12 13:27:22 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "philos.structs.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <sys/time.h>

void				ft_putstr(char *str);
void				print_header(void);
void				print_header_2(void);
void				print_header_3(void);
int					check_ac(int ac);
int					check_wrong_arguments(char **av);
int					checker_is_nall(t_main arg, int ac);
int					checker(int ac, char **av);
int					error_and_exit(void);
int					do_work(t_main *arg);
unsigned long long	gettime_milisec(void);
int					ft_msleep(int mili_sec);
int					set_mtx(t_main	*arg);
unsigned long		ft_atoi(char *str);
void				*routine(void *head);
int					algo_loop(t_philo **head);
void				eating_loop(t_philo **head);
int					simulation_loop(t_main **head);
int					is_death(t_main **head);
int					args_to_struct(t_main *arg, char **av);

#endif
