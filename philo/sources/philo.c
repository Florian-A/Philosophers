/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	Return to the left philosopher
*/
t_list	*get_left_philo(t_list *philo)
{
	if (philo->previous == NULL)
		return (ft_lstlast(philo));
	return (philo->previous);
}

/*
	Creation of a philosopher
*/
int	create_philo(t_cave *cave)
{
	t_philo	*new_philo;
	t_list	*philo_lst;

	philo_lst = cave->philo_lst;
	new_philo = ft_calloc(1, sizeof(t_philo));
	if (!new_philo)
		return (0);
	if (philo_lst != NULL)
		new_philo->id = ((t_philo *)ft_lstlast(philo_lst)->content)->id +1;
	else
		new_philo->id = 1;
	pthread_mutex_init(&new_philo->fork_taken_by_mtx, NULL);
	pthread_mutex_init(&new_philo->nb_eat_mtx, NULL);
	pthread_mutex_init(&new_philo->last_eat_timestamp_mtx, NULL);
	new_philo->time_die = cave->time_die;
	new_philo->last_eat_timestamp = 0;
	new_philo->nb_eat = 0;
	new_philo->fork_taken_by = 0;
	cave->philo_lst = ft_lst_push(philo_lst, new_philo);
	return (1);
}
