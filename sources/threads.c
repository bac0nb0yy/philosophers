/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:34:44 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 08:42:16 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	create_threads_philos(t_args *args, pthread_mutex_t *forks,
	t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_timestamp(&philos[i]);
		if (philos[i].start_time == 0 || philos[i].last_meal == 0)
			return (clear_threads(philos, 0, i),
				clear_all(args, forks, philos), false);
		if (pthread_create(&philos[i].thread_id, NULL, routine,
				(void *)&philos[i]) != 0)
			return (clear_threads(philos, 0, i), clear_all(args, forks, philos),
				ft_print_error_bool(FAIL_THREAD_CREATE, false));
		++i;
	}
	return (true);
}

bool	join_threads_philos(t_args *args, pthread_mutex_t *forks,
	t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		if (pthread_join(philos[i].t_id, NULL) != 0)
			return (clear_threads(philos, 0, args->nb_philos),
				clear_all(args, forks, philos),
				ft_print_error_bool(FAIL_THREAD_JOIN, false));
		++i;
	}
	return (true);
}

bool	create_checker(t_args *args, pthread_mutex_t *forks, t_philo *philos)
{
	pthread_t	checker_thread;

	if (pthread_create(&checker_thread, NULL,
			check, (void *)philos) != 0)
		return (clear_threads(philos, 0, args->nb_philos),
			clear_all(args, forks, philos),
			ft_print_error_bool(FAIL_THREAD_CREATE, false));
	if (pthread_join(checker_thread, NULL) != 0)
	{
		pthread_detach(checker_thread);
		return (clear_threads(philos, 0, args->nb_philos),
			clear_all(args, forks, philos),
			ft_print_error_bool(FAIL_THREAD_JOIN, false));
	}
	return (true);
}

void	*check(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (philos->args->nb_philos_finished != philos->args->nb_philos)
	{
		i = 0;
		while (i < philos->args->nb_philos)
		{
			pthread_mutex_lock(&philos[i].are_alive);
			if (is_dead(&philos[i]))
			{
				// TODO display philo death
				philo->args->philo_dead = true;
				return (pthread_mutex_unlock(&philos[i].are_alive)
					pthread_mutex_unlock(&philos[i].args->check), NULL);
			}
			pthread_mutex_unlock(&philos[i].are_alive);
			if (casted[i].eaten_meals == casted->args->must_eat_times)
				casted->args->satisfied_philos += 1;
			++i;
		}
	}
	return (printf("Every Philosopher had %d meals!\n",
			casted->args->must_eat_times), NULL);
}

bool	threads(t_args *args, pthread_mutex_t *forks, t_philo *philos)
{
	if (!create_threads_philos(args, forks, philos))
		return (false);
	if (!create_checker(args, forks, philos))
		return (false);
	if (!join_threads_philos(args, forks, philos))
		return (false);
	return (true);
}
