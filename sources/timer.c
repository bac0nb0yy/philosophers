/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:58:38 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/25 07:23:59 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_timer(t_philo *philo)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_print_error_bool(FAIL_GETTIME, false));
	philo->start_time = time.tv_sec * S_TO_MICROS + time.tv_usec;
	return (true);
}

size_t	get_timestamp(t_philo *philo)
{
	size_t			timestamp;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_print_error_bool(FAIL_GETTIME, false));
	timestamp = (time.tv_sec * S_TO_MICROS + time.tv_usec) - philo->start_time;
	return (timestamp);
}
