/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine_philo(void *routine_thread)
{
	t_list			*philo_list;
	t_philo			*philo;
	t_philo			*left_philo;
	t_cave			*cave;

	philo_list = ((t_routine_thread *)routine_thread)->philo_lst;
	philo = (t_philo *)philo_list->content;
	cave = ((t_routine_thread *)routine_thread)->cave;
	philo_set_last_eat(philo);
	left_philo = (t_philo *)get_left_philo(philo_list)->content;
	if (philo->id % 2)
		usleep(1500);
	philo_think(cave, philo);
	philo_action(cave, philo, left_philo, routine_thread);
	free(routine_thread);
	return (NULL);
}

void	*routine_doctor(void *routine_thread)
{
	t_cave	*cave;
	t_list	*lst;
	int		philo_hungry;

	cave = (t_cave *)routine_thread;
	lst = cave->philo_lst;
	philo_hungry = 0;
	usleep(100);
	doctor_action(cave, lst, philo_hungry);
	return (NULL);
}

void	routine_cave(t_cave *cave)
{
	t_list				*lst;
	t_routine_thread	*routine_thread;

	lst = cave->philo_lst;
	cave->start_timestamp = ms_timestamp();
	while (lst)
	{
		routine_thread = ft_calloc(1, sizeof(t_routine_thread));
		routine_thread->philo_lst = lst;
		routine_thread->cave = cave;
		pthread_create(&((t_philo *)lst->content)->thread, NULL, \
		routine_philo, routine_thread);
		lst = lst->next;
	}
	pthread_create(&cave->doctor_thread, NULL, \
	routine_doctor, cave);
	lst = cave->philo_lst;
	while (lst)
	{
		pthread_join(((t_philo *)lst->content)->thread, NULL);
		lst = lst->next;
	}
	pthread_join(cave->doctor_thread, NULL);
	if (cave_get_exit(cave))
		printf("%lld %d died \n", cave->died_timestamp, cave->died_id);
}
