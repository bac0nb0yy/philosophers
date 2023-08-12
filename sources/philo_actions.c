/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:59:19 by dtelnov           #+#    #+#             */
/*   Updated: 2023/08/12 13:28:21 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_direction_lock(t_philo *philos)
{
	if (philos->num % 2 == 0)
	{
		pthread_mutex_lock(philos->r_fork);
		display_msg(philos, FORK);
		pthread_mutex_lock(philos->l_fork);
		display_msg(philos, FORK);
	}
	else
	{
		pthread_mutex_lock(philos->l_fork);
		display_msg(philos, FORK);
		pthread_mutex_lock(philos->r_fork);
		display_msg(philos, FORK);
	}
}

void	philo_eat(t_philo *philos)
{
	handle_direction_lock(philos);
	display_msg(philos, EAT);
	pthread_mutex_lock(philos->args->m_last_meal);
	philos->last_meal = get_current_time();
	pthread_mutex_unlock(philos->args->m_last_meal);
	ft_usleep(philos->args->t_eat * 1000);
	pthread_mutex_lock(philos->args->m_count_meals);
	philos->count_meals++;
	pthread_mutex_unlock(philos->args->m_count_meals);
	if (philos->num % 2 == 0)
	{
		pthread_mutex_unlock(philos->r_fork);
		pthread_mutex_unlock(philos->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philos->l_fork);
		pthread_mutex_unlock(philos->r_fork);
	}
}

void	philo_sleep(t_philo *philos)
{
	display_msg(philos, SLEEP);
	ft_usleep(philos->args->t_sleep * 1000);
}

void	*life(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->args->nb_philos == 1)
		return (case_one_philo(philos));
	if (!(philos->num % 2))
		ft_usleep(500);
	while (!everyone_ate(philos) && !someone_die(philos))
	{
		philo_eat(philos);
		philo_sleep(philos);
		display_msg(philos, THINK);
		if (philos->args->t_sleep <= philos->args->t_eat)
			ft_usleep(((philos->args->t_eat - philos->args->t_sleep) * 1000)
				+ 250);
	}
	return (NULL);
}
