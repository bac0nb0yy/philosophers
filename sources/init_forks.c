/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:45:13 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 09:57:18 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*malloc_forks(int size)
{
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * size);
	return (forks);
}

bool	init_forks(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (clear_forks(forks, i),
				ft_print_error_bool(FAIL_MUTEX_INIT, false));
		++i;
	}
	return (true);
}
