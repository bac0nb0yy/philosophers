/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:34:44 by dtelnov           #+#    #+#             */
/*   Updated: 2023/08/12 13:33:59 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	create_threads_philos(t_args *args, pthread_mutex_t *forks,
	t_philo *philos, pthread_mutex_t *all_mutex)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		philos[i].last_meal = get_current_time();
		if (philos[i].last_meal == 0)
			return (clear_threads(philos, 0, i),
				clear_all(args, forks, philos, all_mutex), false);
		if (pthread_create(&philos[i].thread_id, NULL, life,
				(void *)&philos[i]) != 0)
			return (clear_threads(philos, 0, i),
				clear_all(args, forks, philos, all_mutex),
				ft_print_error_bool(FAIL_THREAD_CREATE, false));
		++i;
	}
	return (true);
}

bool	join_threads_philos(t_args *args, pthread_mutex_t *forks,
	t_philo *philos, pthread_mutex_t *all_mutex)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		if (pthread_join(philos[i].thread_id, NULL) != 0)
			return (clear_threads(philos, 0, args->nb_philos),
				clear_all(args, forks, philos, all_mutex),
				ft_print_error_bool(FAIL_THREAD_JOIN, false));
		++i;
	}
	return (true);
}

bool	check_everyone_eat(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->nb_philos)
	{
		if (!is_philo_finish(&philos[i]))
			return (false);
		++i;
	}
	return (true);
}

void	check_death(t_philo *philos)
{
	int		i;

	while (!everyone_ate(philos) && !someone_die(philos))
	{
		usleep(900);
		i = 0;
		while (i < philos->args->nb_philos)
		{
			if (is_philo_dead(&philos[i]))
			{
				display_msg(&philos[i], DEAD);
				pthread_mutex_lock(philos->args->m_dead);
				philos->args->philo_dead = true;
				pthread_mutex_unlock(philos->args->m_dead);
			}
			else if (check_everyone_eat(philos))
			{
				pthread_mutex_lock(philos->args->m_finish);
				philos->args->philos_finished_eat = true;
				pthread_mutex_unlock(philos->args->m_finish);
			}
			++i;
		}
	}
}

bool	threads(t_args *args, pthread_mutex_t *forks, t_philo *philos,
					pthread_mutex_t *all_mutex)
{
	philos->args->start_time = get_current_time();
	if (!create_threads_philos(args, forks, philos, all_mutex))
		return (false);
	check_death(philos);
	if (!join_threads_philos(args, forks, philos, all_mutex))
		return (false);
	if (args->philos_finished_eat)
		printf("Everyone has eaten\n");
	return (true);
}
