/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:56:27 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 07:53:05 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_threads(t_philo *philos, int start, int end)
{
	int	i;

	if (philos)
	{
		i = start;
		while (i < end)
		{
			pthread_detach(philos[i].thread_id);
			++i;
		}
	}
}

void	clear_philos(t_philo *philos, int size_to_clear)
{
	int	i;

	if (philos)
	{
		i = 0;
		while (i < size_to_clear)
		{
			pthread_mutex_destroy(&philos[i].is_alive);
			philos[i].l_fork = NULL;
			philos[i].r_fork = NULL;
			++i;
		}
		free(philos);
		philos = NULL;
	}
}

void	clear_args(t_args *args)
{
	args = NULL;
}

void	clear_forks(pthread_mutex_t *forks, int size_to_clear)
{
	int	i;

	if (forks)
	{
		i = 0;
		while (i < size_to_clear)
		{
			pthread_mutex_destroy(&forks[i]);
			++i;
		}
		free(forks);
		forks = NULL;
	}
}

void	clear_all(t_args *args, pthread_mutex_t *forks, t_philo *philos)
{
	clear_philos(philos, args->nb_philos);
	clear_forks(forks, args->nb_philos);
	clear_args(args);
}
