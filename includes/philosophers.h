/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:51:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 14:04:30 by dtelnov          ###   ########.fr       */
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
# define FAIL_THREAD_CREATE		"Thread creation failed\n"
# define FAIL_THREAD_JOIN		"Thread join failed\n"

# define S_TO_MICROS			1000000
# define S_TO_MILLIS			1000
# define MICROS_TO_MILLIS		1000	

# define FORK					"has taken a fork"
# define EAT					"is eating"
# define SLEEP					"is sleeping"
# define THINK					"is thinking"
# define DEAD					"died"
# define END 					"Everyone have eaten"

# define RESET 					"\033[0m"

# define YELLOW					"\033[0;33m"
# define GREEN 					"\033[0;32m"
# define BLUE					"\033[0;34m"
# define RED  					"\033[0;31m"
# define PURPLE  				"\033[0;35m"
# define CYAN  					"\033[0;36m"
# define BLACK  				"\033[0;30m"
# define WHITE  				"\033[0;37m"

# define BYELLOW  				"\033[1;33m"
# define BGREEN  				"\033[1;32m"
# define BBLUE  				"\033[1;34m"
# define BRED  					"\033[1;31m"
# define BPURPLE 				"\033[1;35m"
# define BCYAN 					"\033[1;36m"
# define BBLACK 				"\033[1;30m"
# define BWHITE 				"\033[1;37m"

typedef struct s_args
{
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				min_meals;
	int				nb_philos_finished;
	bool			philo_dead;
	bool			philo_eat;
	pthread_mutex_t	check;
}		t_args;

typedef struct s_philo
{
	unsigned int	num;
	pthread_t		thread_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	are_alive;
	size_t			last_meal;
	int				count_meals;
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
size_t			get_current_time(void);
void			clear_threads(t_philo *philos, int start, int end);
bool			threads(t_args *args, pthread_mutex_t *forks, t_philo *philos);
bool			join_threads_philos(t_args *args, pthread_mutex_t *forks,
					t_philo *philos);
bool			create_threads_philos(t_args *args, pthread_mutex_t *forks,
					t_philo *philos);
bool			create_checker(t_args *args, pthread_mutex_t *forks,
					t_philo *philos);
void			*check(void *arg);
bool			is_dead(t_philo *philo);
void			philo_eat_min_meals(t_philo *philo);
void			ft_usleep(size_t time);
void			*case_one_philo(t_philo *philo);
void			display_msg(t_philo *philos, char *action);
void			*life(void *arg);
void			philo_sleep(t_philo *philos);
void			philo_eat(t_philo *philos);
#endif
