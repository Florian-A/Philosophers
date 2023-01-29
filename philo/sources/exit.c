/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	error_exit(t_cave *cave, char *str)
{
	t_list	*lst;

	lst = cave->philo_lst;
	while (lst)
	{
		pthread_mutex_destroy(&((t_philo *)lst->content)->fork_taken_by_mtx);
		pthread_mutex_destroy(&((t_philo *)lst->content)->nb_eat_mtx);
		pthread_mutex_destroy(&((t_philo *)lst->content)->\
		last_eat_timestamp_mtx);
		lst = lst->next;
	}
	ft_lstclear(&cave->philo_lst, free);
	printf("%s", str);
	return (1);
}

int	normal_exit(t_cave *cave)
{
	t_list	*lst;

	lst = cave->philo_lst;
	while (lst)
	{
		pthread_mutex_destroy(&((t_philo *)lst->content)->fork_taken_by_mtx);
		pthread_mutex_destroy(&((t_philo *)lst->content)->nb_eat_mtx);
		pthread_mutex_destroy(&((t_philo *)lst->content)->\
		last_eat_timestamp_mtx);
		lst = lst->next;
	}
	pthread_mutex_destroy(&cave->min_eat_mtx);
	pthread_mutex_destroy(&cave->exit_mtx);
	ft_lstclear(&cave->philo_lst, free);
	return (0);
}
