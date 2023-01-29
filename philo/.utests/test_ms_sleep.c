/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	test_ms_sleep_a(void)
{
	long long	t1;
	long long	t2;
	long long	t3;
	t_cave		cave;

	init_cave(&cave);
	cave.time_die = 1000;
	t1 = ms_timestamp();
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	ms_sleep(&cave, 5);
	t2 = ms_timestamp();
	t3 = ms_betwen(t1, t2);
	if (t3 >= 50 && t3 <= 53)
		return (0);
	return (-1);
}

int	test_ms_sleep(void)
{
	if (test_ms_sleep_a() == -1)
		return (-1);
	return (0);
}
