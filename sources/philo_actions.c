/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:59:19 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 11:54:10 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->l_fork);
	display_msg(philos, FORK);
	pthread_mutex_lock(philos->r_fork);
	display_msg(philos, FORK);
	philos->last_meal = get_current_time();
	display_msg(philos, EAT);
	ft_usleep(philos->args->t_eat * 1000);
	pthread_mutex_unlock(philos->l_fork);
	pthread_mutex_unlock(philos->r_fork);
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
	while (philos->args->nb_philos_finished != philos->args->nb_philos
		&& !philos->args->philo_dead)
	{
		if (philos->num % 2 == 1)
			ft_usleep(1000);
		if (philos->args->nb_philos == 1)
			return (case_one_philo(philos));
		philo_eat(philos);
		philo_sleep(philos);
		display_msg(philos, THINK);
	}
	return (NULL);
}
