/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:58:38 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/22 04:07:26 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	initialization_timer(t_timer *timer)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (ft_print_error_bool(FAIL_GETTIME, false));
	timer->start_seconds = current_time.tv_sec;
	timer->start_microseconds = current_time.tv_usec;
	timer->timestamp = 0;
	return (true);
}

bool	update_timer(t_timer *timer)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (ft_print_error_bool(FAIL_GETTIME, false));
	timer->seconds = current_time.tv_sec;
	timer->microseconds = current_time.tv_usec;
	timer->timestamp = (((timer->seconds - timer->start_seconds) * 1000)
			+ (timer->microseconds - timer->start_microseconds) / 1000);
	return (true);
}
