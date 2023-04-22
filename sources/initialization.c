/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:51:45 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/22 03:15:05 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialization_nb_philos(int data, t_args *args)
{
	args->nb_philos = data;
}

void	initialization_t_die(int data, t_args *args)
{
	args->t_die = data;
}

void	initialization_t_eat(int data, t_args *args)
{
	args->t_eat = data;
}

void	initialization_t_sleep(int data, t_args *args)
{
	args->t_sleep = data;
}

bool	initialization_args(int ac, char **av, t_args *args)
{
	static void	(*give_value[])(int, t_args *)
		= {initialization_nb_philos, initialization_t_die,
		initialization_t_eat, initialization_t_sleep};
	long		data;
	int			i;

	i = 1;
	while (i < 5)
	{
		if (!ft_atoi(&data, av[i]))
			return (ft_print_error_bool(FAIL_INITIALIZATION, false));
		give_value[i - 1](data, args);
		data = 0;
		++i;
	}
	if (ac == 6)
	{
		if (!ft_atoi(&data, av[i]))
			return (ft_print_error_bool(FAIL_INITIALIZATION, false));
		args->nb_philos_eat = data;
	}
	args->size = ac - 1;
	return (true);
}
