/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:01:26 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 14:23:20 by dtelnov          ###   ########.fr       */
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
	pthread_mutex_lock(philo->l_fork);
	display_msg(philo, FORK);
	philo->last_meal = get_current_time();
	return (NULL);
}

void	display_msg(t_philo *philos, char *action)
{
	size_t	timestamp;

	timestamp = get_current_time() - philos->start_time;
	pthread_mutex_lock(&philos->args->check);
	if (philos->args->philo_dead == false)
		printf("%zu Philosopher %u %s\n", timestamp / 1000, philos->num, action);
	pthread_mutex_unlock(&philos->args->check);
}
