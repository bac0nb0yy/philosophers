/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:12:08 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/03 01:25:12 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_args			args;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*all_mutex;

	all_mutex = malloc_mutex();
	if (!all_mutex)
		return (ft_print_error_bool(FAIL_MALLOC, EXIT_FAILURE));
	if (!check_ac(ac) || !init_args(ac, av, &args, all_mutex))
		return (ft_print_error_bool(FAIL_ERROR, EXIT_FAILURE));
	forks = malloc_forks(args.nb_philos);
	if (!forks)
		return (ft_print_error_bool(FAIL_MALLOC, EXIT_FAILURE));
	if (!init_forks(forks, args.nb_philos))
		return (ft_print_error_bool(FAIL_ERROR, EXIT_FAILURE));
	philos = malloc_philos(args.nb_philos);
	if (!philos)
		return (ft_print_error_bool(FAIL_MALLOC, EXIT_FAILURE));
	if (!init_philos(philos, &args, forks))
		return (ft_print_error_bool(FAIL_ERROR, EXIT_FAILURE));
	if (!threads(&args, forks, philos, all_mutex))
		return (ft_print_error_bool(FAIL_ERROR, EXIT_FAILURE));
	clear_all(&args, forks, philos, all_mutex);
}
