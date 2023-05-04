/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:34:29 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/02 19:24:47 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	everyone_ate(t_philo *philos)
{
	bool	value;

	pthread_mutex_lock(philos->args->m_finish);
	value = philos->args->philos_finished_eat;
	pthread_mutex_unlock(philos->args->m_finish);
	return (value);
}

bool	someone_die(t_philo *philos)
{
	bool	value;

	pthread_mutex_lock(philos->args->m_dead);
	value = philos->args->philo_dead;
	pthread_mutex_unlock(philos->args->m_dead);
	return (value);
}

bool	is_philo_dead(t_philo *philo)
{
	bool	value;

	value = false;
	pthread_mutex_lock(philo->args->m_last_meal);
	if ((int)((get_current_time() - philo->last_meal) / MICROS_TO_MILLIS)
		>= philo->args->t_die)
		value = true;
	pthread_mutex_unlock(philo->args->m_last_meal);
	return (value);
}

bool	is_philo_finish(t_philo *philo)
{
	bool	value;

	value = false;
	pthread_mutex_lock(philo->args->m_count_meals);
	if (philo->count_meals >= philo->args->min_meals
		&& philo->args->min_meals > 0)
		value = true;
	pthread_mutex_unlock(philo->args->m_count_meals);
	return (value);
}
