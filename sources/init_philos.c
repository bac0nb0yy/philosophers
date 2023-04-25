/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:51:29 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 06:23:56 by dtelnov          ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i < args->nb_philos)
	{
		philos[i].num = i + 1;
		philos[i].count_meals = 0;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % args->nb_philos];
		philos[i].last_meal = -1;
		if (pthread_mutex_init(&philos[i].is_alive, NULL) != 0)
			return (clear_philos(philos, i), clear_forks(forks,
					args->nb_philos), clear_args(args),
				ft_print_error_bool(FAIL_MUTEX_INIT, false));
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
