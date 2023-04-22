/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:12:08 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/22 04:07:29 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_timer	timer;

	if (!check_ac(ac))
		return (ft_print_error_bool(FAIL_ERROR, false));
	if (!initialization_args(ac, av, &args))
		return (ft_print_error_bool(FAIL_ERROR, false));
	if (!initialization_timer(&timer))
		return (ft_print_error_bool(FAIL_ERROR, false));
}
