/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:12:08 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 07:19:36 by dtelnov          ###   ########.fr       */
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
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (!check_ac(ac) || !init_args(ac, av, &args))
		return (ft_print_error_bool(FAIL_ERROR, false));
	display_args(&args);
	forks = malloc_forks(args.nb_philos);
	if (forks == NULL)
		return (ft_print_error_bool(FAIL_MALLOC, false));
	if (!init_forks(forks, args.nb_philos))
		return (ft_print_error_bool(FAIL_ERROR, false));
	philos = malloc_philos(args.nb_philos);
	if (philos == NULL)
		return (ft_print_error_bool(FAIL_MALLOC, false));
	if (!init_philos(philos, &args, forks))
		return (ft_print_error_bool(FAIL_ERROR, false));
	display_philos(philos);
	clear_all(&args, forks, philos);
}
