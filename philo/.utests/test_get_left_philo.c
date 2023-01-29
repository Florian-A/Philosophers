/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_left_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	test_get_left_philo_a(void)
{
	t_cave	cave;

	init_cave(&cave);
	if (create_philo(&cave) == 0)
		return (-1);
	if (create_philo(&cave) == 0)
		return (-1);
	if (create_philo(&cave) == 0)
		return (-1);
	if (((t_philo *)get_left_philo(cave.philo_lst)->content)->id != 3)
		return (-1);
	if (((t_philo *)get_left_philo(cave.philo_lst->\
	next)->content)->id != 1)
		return (-1);
	if (((t_philo *)get_left_philo(cave.philo_lst->\
	next->next)->content)->id != 2)
		return (-1);
	ft_lstclear(&cave.philo_lst, free);
	return (0);
}

static int	test_get_left_philo_b(void)
{
	t_cave	cave;

	init_cave(&cave);
	if (create_philo(&cave) == 0)
		return (-1);
	if (((t_philo *)get_left_philo(cave.philo_lst)->content)->id != 1)
		return (-1);
	ft_lstclear(&cave.philo_lst, free);
	return (0);
}

int	test_get_left_philo(void)
{
	if (test_get_left_philo_a() == -1)
		return (-1);
	if (test_get_left_philo_b() == -1)
		return (-1);
	return (0);
}
