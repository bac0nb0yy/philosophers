/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:12:08 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 08:49:36 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_args			args;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (!check_ac(ac) || !init_args(ac, av, &args))
		return (ft_print_error_bool(FAIL_ERROR, false));
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
	// printf("nb philos finished : %d\n", philos->args->nb_philos_finished);
	// philos[2].count_meals = philos->args->min_meals;
	// philo_eat_min_meals(&philos[2]);
	// printf("nb philos finished : %d\n", philos->args->nb_philos_finished);
	clear_all(&args, forks, philos);
}
