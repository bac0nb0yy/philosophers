/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:48:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/03 01:29:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_atoi(long *result, char *array)
{
	int			i;

	if (array[0] == '-')
		return (ft_print_error_bool(FAIL_PARSING_NEGATIVE, false));
	i = 0;
	*result = 0;
	while (array[i])
	{
		if (!ft_isdigit((int) array[i]))
			return (ft_print_error_bool(FAIL_PARSING_DIGITS, false));
		*result = (*result * 10) + (array[i] - '0');
		if (*result > INT_MAX)
			return (ft_print_error_bool(FAIL_PARSING_OVERFLOW, false));
		++i;
	}
	if (*result == 0)
		return (ft_print_error_bool(FAIL_PARSING_NEGATIVE, false));
	return (true);
}

bool	check_ac(int ac)
{
	if (ac < 5)
		return (printf("Too few arguments\n%s", USAGE), false);
	if (ac > 6)
		return (printf("Too many arguments\n%s", USAGE), false);
	return (true);
}
