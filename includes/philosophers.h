/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:51:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 07:28:55 by dtelnov          ###   ########.fr       */
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

# define USAGE					"Usage: ./philo number_of_philos time_to_die \
								time_to_eat time_to_sleep \
								[number_of_times_each_philo_must_eat]\n"
# define FAIL_PARSING_DIGITS	"Not only digits detected\n"
# define FAIL_PARSING_OVERFLOW	"Overflow detected\n"
# define FAIL_PARSING_UNDERFLOW	"Underflow detected\n"
# define FAIL_ERROR				"Error occured\n"
# define FAIL_INIT				"Initialization failed\n"
# define FAIL_GETTIME			"Function getttimeoftheday failed\n"
# define FAIL_PARSING_NEGATIVE	"Negative argument found\n"
# define FAIL_MALLOC			"Malloc() failed\n"
# define FAIL_MUTEX_INIT		"Initialization of a mutex failed\n"

# define S_TO_MICROS			1000000
# define S_TO_MILLIS			1000
# define MICROS_TO_MILLIS		1000	

typedef struct s_args
{
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				min_meals;
	int				nb_philos_finished;
	bool			philo_dead;
	pthread_mutex_t	check;
}		t_args;

typedef struct s_philo
{
	unsigned int	num;
	pthread_t		thread_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	is_alive;
	size_t			last_meal;
	unsigned int	count_meals;
	size_t			start_time;
	t_args			*args;
}		t_philo;

bool			ft_atoi(long *result, char *array);
bool			check_ac(int ac);
bool			ft_isdigit(int c);
bool			ft_print_error_bool(char *error_msg, bool boolean);
bool			init_args(int ac, char **av, t_args *args);
void			t_sleep(int data, t_args *args);
void			t_eat(int data, t_args *args);
void			t_die(int data, t_args *args);
void			philos(int data, t_args *args);
void			display_args(t_args *args);
void			display_actual_time(void);
bool			init_timer(t_philo *philo);
pthread_mutex_t	*malloc_forks(int size);
bool			init_forks(pthread_mutex_t *forks, int size);
void			clear_forks(pthread_mutex_t *forks, int size_to_clear);
void			clear_args(t_args *args);
void			clear_philos(t_philo *philos, int size_to_clear);
void			clear_all(t_args *args, pthread_mutex_t *forks,
					t_philo *philos);
t_philo			*malloc_philos(int size);
bool			init_philos(t_philo *philos, t_args *args,
					pthread_mutex_t *forks);
void			display_philos(t_philo *philos);
size_t			get_timestamp(t_philo *philo);
#endif
