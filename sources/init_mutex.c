/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:45:36 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/03 01:40:33 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*malloc_mutex(void)
{
	pthread_mutex_t	*all_mutex;

	all_mutex = malloc(sizeof(pthread_mutex_t) * 5);
	return (all_mutex);
}

bool	init_mutex(t_args *args, pthread_mutex_t *all_mutex)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (i == 0 && pthread_mutex_init(&all_mutex[i], NULL) == 0)
			args->m_display = &all_mutex[i];
		else if (i == 1 && pthread_mutex_init(&all_mutex[i], NULL) == 0)
			args->m_dead = &all_mutex[i];
		else if (i == 2 && pthread_mutex_init(&all_mutex[i], NULL) == 0)
			args->m_count_meals = &all_mutex[i];
		else if (i == 3 && pthread_mutex_init(&all_mutex[i], NULL) == 0)
			args->m_last_meal = &all_mutex[i];
		else if (i == 4 && pthread_mutex_init(&all_mutex[i], NULL) == 0)
			args->m_finish = &all_mutex[i];
		else
			return (clear_mutex(all_mutex, args, 0, i),
				ft_print_error_bool(FAIL_MUTEX_INIT, false));
		++i;
	}
	return (true);
}
