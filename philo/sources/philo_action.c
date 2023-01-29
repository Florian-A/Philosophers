/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	The philo's actions are:
	*1. Check if a philosopher has not died in the cave
	*2. Check that a philosopher has priority to eat
	*3. If a philosopher has eaten, trigger his sleep and thinking.  
*/
void	philo_action(t_cave *cave, t_philo *philo, t_philo *left_philo, \
void *routine_thread)
{
	int	i;

	i = 1;
	while (1)
	{
		if (cave->max_eat != 0 && i > cave->max_eat)
			break ;
		if (cave_get_exit(cave))
			break ;
		if (philo_eq_min_eat(cave, philo))
		{
			if (philo_eat(((t_routine_thread *)routine_thread)-> \
			cave, philo, left_philo))
			{
				philo_sleep(((t_routine_thread *)routine_thread)-> \
				cave, philo);
				philo_think(((t_routine_thread *)routine_thread)-> \
				cave, philo);
				i++;
			}
		}
		else
			usleep(50);
	}
}

void	philo_sleep(t_cave *cave, t_philo *philo)
{
	if (cave_get_exit(cave) != 1)
		msg_log(cave, philo->id, "is sleeping", 0);
	if (cave_get_exit(cave) != 1)
		ms_sleep(cave, cave->time_sleep);
}

void	philo_think(t_cave *cave, t_philo *philo)
{
	if (cave_get_exit(cave) != 1)
		msg_log(cave, philo->id, "is thinking", 0);
}

/*
	Return 1 when the philosopher take two forks
*/
int	philo_take_two_fork(t_cave *cave, t_philo *philo, t_philo *left_philo)
{
	if (philo_get_fork_taken_by(philo) == philo->id && cave_get_exit(cave) != 1)
		;
	else if (philo_get_fork_taken_by(philo) == 0 && cave_get_exit(cave) != 1)
	{
		philo_set_fork_taken_by(philo, philo->id);
		msg_log(cave, philo->id, "has taken a fork", 0);
	}
	else
		return (0);
	if (philo_get_fork_taken_by(left_philo) == philo->id && \
	philo->id != left_philo->id && cave_get_exit(cave) != 1)
		;
	else if (philo_get_fork_taken_by(left_philo) == 0 \
	&& cave_get_exit(cave) != 1)
	{
		philo_set_fork_taken_by(left_philo, philo->id);
		msg_log(cave, philo->id, "has taken a fork", 0);
	}
	else
		return (0);
	return (1);
}

/*
	If the philosopher get the two forks, start eat
*/
int	philo_eat(t_cave *cave, t_philo *philo, \
t_philo *left_philo)
{
	if (philo_take_two_fork(cave, philo, left_philo) && \
	cave_get_exit(cave) != 1)
	{
		philo_set_last_eat(philo);
		msg_log(cave, philo->id, "is eating", 0);
		philo_increase_nb_eat(philo);
		ms_sleep(cave, cave->time_eat);
		philo_set_fork_taken_by(philo, 0);
		philo_set_fork_taken_by(left_philo, 0);
		return (1);
	}
	return (0);
}
