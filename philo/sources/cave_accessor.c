/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave_accessor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	cave_get_exit(t_cave *cave)
{
	int	get_exit;

	pthread_mutex_lock(&cave->exit_mtx);
	get_exit = cave->exit;
	pthread_mutex_unlock(&cave->exit_mtx);
	return (get_exit);
}

void	cave_set_exit(t_cave *cave)
{
	pthread_mutex_lock(&cave->exit_mtx);
	cave->exit = 1;
	pthread_mutex_unlock(&cave->exit_mtx);
}

void	cave_increase_min_eat(t_cave *cave)
{
	pthread_mutex_lock(&cave->min_eat_mtx);
	cave->min_eat++;
	pthread_mutex_unlock(&cave->min_eat_mtx);
}

void	cave_set_min_eat(t_cave *cave, t_philo *philo)
{
	pthread_mutex_lock(&cave->min_eat_mtx);
	pthread_mutex_lock(&philo->nb_eat_mtx);
	cave->min_eat = philo->nb_eat;
	pthread_mutex_unlock(&philo->nb_eat_mtx);
	pthread_mutex_unlock(&cave->min_eat_mtx);
}
