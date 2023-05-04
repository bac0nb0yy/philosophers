/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:01:26 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/03 21:26:02 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	everyone_finished(t_philo *philos)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < philos->args->nb_philos)
	{
		if (philos[i].count_meals == philos->args->min_meals)
			++count;
		++i;
	}
	return (count);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() < start + time)
		usleep(500);
}

void	*case_one_philo(t_philo *philo)
{
	display_msg(philo, FORK);
	pthread_mutex_lock(philo->args->m_last_meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->args->m_last_meal);
	return (NULL);
}

void	display_msg(t_philo *philos, char *action)
{
	pthread_mutex_lock(philos->args->m_display);
	if (!someone_die(philos) && !everyone_ate(philos))
		printf("%zu Philosopher %u %s\n",
			(get_current_time() - philos->args->start_time) / 1000,
			philos->num, action);
	pthread_mutex_unlock(philos->args->m_display);
}
