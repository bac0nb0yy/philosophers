/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:51:45 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 04:31:54 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philos(int data, t_args *args)
{
	args->nb_philos = data;
}

void	t_die(int data, t_args *args)
{
	args->t_die = data;
}

void	t_eat(int data, t_args *args)
{
	args->t_eat = data;
}

void	t_sleep(int data, t_args *args)
{
	args->t_sleep = data;
}

bool	init_args(int ac, char **av, t_args *args, pthread_mutex_t *all_mutex)
{
	static void	(*f[])(int, t_args *) = {philos, t_die, t_eat, t_sleep};
	long		data;
	int			i;

	i = 1;
	while (i < 5)
	{
		if (!ft_atoi(&data, av[i]) || (i > 1 && data >= INT_MAX / 10))
			return (ft_print_error_bool(FAIL_INIT, false));
		f[i - 1](data, args);
		++i;
	}
	args->min_meals = -1;
	if (ac == 6)
	{
		if (!ft_atoi(&data, av[i]))
			return (ft_print_error_bool(FAIL_INIT, false));
		args->min_meals = data;
	}
	args->philo_dead = false;
	args->philos_finished_eat = false;
	if (!init_mutex(args, all_mutex))
		return (ft_print_error_bool(FAIL_INIT, false));
	return (true);
}
