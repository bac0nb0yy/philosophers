/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:51:29 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/04 00:40:33 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*malloc_philos(int size)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * size);
	return (philos);
}

bool	init_philos(t_philo *philos, t_args *args, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		philos[i].num = i + 1;
		philos[i].count_meals = 0;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % args->nb_philos];
		philos[i].args = args;
		++i;
	}
	return (true);
}

void	display_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->nb_philos)
	{
		printf("Philo number : %u\n", philos[i].num);
		++i;
	}
}
