/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctor_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	Declares the death of a philosopher
*/
void	doctor_set_death(t_cave *cave, t_list *lst)
{
	cave->died_timestamp = ms_from_start(cave);
	cave->died_id = ((t_philo *)lst->content)->id;
	cave_set_exit(cave);
}

/*
	The doctor's actions are:
	*1. Compare the last timestamp when a philosopher has eaten with \
	the lifetime limit
	*2. Prioritize the philosophers who have not yet eaten
*/
void	doctor_action(t_cave *cave, t_list *lst, int philo_hungry)
{
	while (lst)
	{
		if (philo_get_last_eat((t_philo *)lst->content) > cave->time_die)
		{
			doctor_set_death(cave, lst);
			break ;
		}
		if (philo_get_nb_eat((t_philo *)lst->content) < cave->min_eat)
		{
			cave_set_min_eat(cave, (t_philo *)lst->content);
			philo_hungry = 1;
		}
		if (lst->next)
			lst = lst->next;
		if (lst && lst->next == NULL)
		{
			if (philo_hungry == 0 && \
			cave->max_eat != 0 && cave->min_eat == cave->max_eat)
				break ;
			lst = ft_lstfirst(lst);
			if (philo_hungry == 0)
				cave_increase_min_eat(cave);
			philo_hungry = 0;
		}
	}
}
