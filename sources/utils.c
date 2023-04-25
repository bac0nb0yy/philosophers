/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:05:39 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 08:48:35 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat_min_meals(t_philo *philo)
{
	if (philo->count_meals == philo->args->min_meals)
		philo->args->nb_philos_finished += 1;
}

bool	is_dead(t_philo *philo)
{
	return (((int)(get_current_time() - philo->last_meal)
		>= philo->args->t_die));
}

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_print_error_bool(char *error_msg, bool boolean)
{
	return (printf("%s", error_msg), boolean);
}

void	display_args(t_args *args)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (i == 0)
			printf("number_of_philosophers: %d\n", args->nb_philos);
		else if (i == 1)
			printf("time_to_die: %d\n", args->t_die);
		else if (i == 2)
			printf("time_to_eat: %d\n", args->t_eat);
		else if (i == 3)
			printf("time_to_sleep: %d\n", args->t_sleep);
		else if (i == 4 && args->min_meals != -1)
			printf("number_of_times_each_philosopher_must_eat: %d\n",
				args->min_meals);
		++i;
	}
}
