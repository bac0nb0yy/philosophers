/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:51:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/22 06:13:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

# define USAGE "Usage: ./philo number_of_philos time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philo_must_eat]\n"
# define FAIL_PARSING_DIGITS	"Not only digits detected\n"
# define FAIL_PARSING_OVERFLOW	"Overflow detected\n"
# define FAIL_PARSING_UNDERFLOW	"Underflow detected\n"
# define FAIL_ERROR				"Error occured\n"
# define FAIL_INITIALIZATION	"Initialization failed\n"
# define FAIL_GETTIME			"Function getttimeoftheday failed\n"

typedef struct s_args
{
	int	nb_philos;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_philos_eat;
	int	size;
}		t_args;

typedef struct s_timer
{
	long	start_seconds;
	long	seconds;
	long	start_microseconds;
	long	microseconds;
	long	timestamp;
}		t_timer;

bool	ft_atoi(long *result, char *array);
bool	check_ac(int ac);
bool	ft_isdigit(int c);
bool	ft_print_error_bool(char *error_msg, bool boolean);
bool	initialization_args(int ac, char **av, t_args *args);
void	initialization_t_sleep(int data, t_args *args);
void	initialization_t_eat(int data, t_args *args);
void	initialization_t_die(int data, t_args *args);
void	initialization_nb_philos(int data, t_args *args);
void	display_args(t_args *args);
void	display_actual_time(void);
bool	initialization_timer(t_timer *timer);
bool	update_timer(t_timer *timer);
#endif
