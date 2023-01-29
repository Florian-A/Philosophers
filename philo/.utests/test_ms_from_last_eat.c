/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_from_last_eat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	test_ms_from_last_eat_a(void)
{
	long long		t1;
	t_cave			cave;

	init_cave(&cave);
	cave.time_die = 1000;
	if (create_philo(&cave) == 0)
		return (-1);
	((t_philo *)cave.philo_lst->content)->\
	last_eat_timestamp = ms_timestamp();
	ms_sleep(&cave, 500);
	t1 = ms_from_last_eat((t_philo *)cave.philo_lst->content);
	ft_lstclear(&cave.philo_lst, free);
	if (t1 == 500)
		return (0);
	return (-1);
}

int	test_ms_from_last_eat(void)
{
	if (test_ms_from_last_eat_a() == -1)
		return (-1);
	return (0);
}
