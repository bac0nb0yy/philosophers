/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:12:08 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/22 06:08:09 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher(void *arg)
{
	int	id;

	id = *(int *)arg;
	printf("Philosopher %d is thinking...\n", id);
	printf("Philosopher %d is eating...\n", id);
	printf("Philosopher %d is done.\n", id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args			args;
	t_timer			timer;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	int				*ids;

	if (!check_ac(ac))
		return (ft_print_error_bool(FAIL_ERROR, false));
	if (!initialization_args(ac, av, &args))
		return (ft_print_error_bool(FAIL_ERROR, false));
	if (!initialization_timer(&timer))
		return (ft_print_error_bool(FAIL_ERROR, false));
	threads = malloc(sizeof(pthread_t) * args.nb_philos);
	ids = malloc(sizeof(int) * args.nb_philos);
	forks = malloc(sizeof(pthread_mutex_t) * args.nb_philos);
	for (int i = 0; i < 5; i++)
	{
		ids[i] = i;
		pthread_create(&threads[i], NULL, philosopher, &ids[i]);
	}
	for (int i = 0; i < 5; i++)
		pthread_join(threads[i], NULL);
}
