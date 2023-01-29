/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_accessor1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	Return 1 if philosopher has as much to eat as the other philosophers, \
	or 0 if he has priority to eat
*/
int	philo_eq_min_eat(t_cave *cave, t_philo *philo)
{
	int	nb_eat_eq_min_eat;

	nb_eat_eq_min_eat = 0;
	pthread_mutex_lock(&cave->min_eat_mtx);
	if (philo->nb_eat == cave->min_eat)
		nb_eat_eq_min_eat = 1;
	pthread_mutex_unlock(&cave->min_eat_mtx);
	return (nb_eat_eq_min_eat);
}

/*
	Set the last timestamp when a philosopher has eaten
*/
void	philo_set_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat_timestamp_mtx);
	philo->last_eat_timestamp = ms_timestamp();
	pthread_mutex_unlock(&philo->last_eat_timestamp_mtx);
}

/*
	Get the last timestamp when a philosopher has eaten
*/
long long	philo_get_last_eat(t_philo *philo)
{
	long long	last_eat_timestamp;

	pthread_mutex_lock(&philo->last_eat_timestamp_mtx);
	last_eat_timestamp = ms_betwen(philo->last_eat_timestamp, ms_timestamp());
	pthread_mutex_unlock(&philo->last_eat_timestamp_mtx);
	return (last_eat_timestamp);
}

/*
	Get the number of times a philosopher has eaten
*/
int	philo_get_nb_eat(t_philo *philo)
{
	int	nb_eat;

	nb_eat = 0;
	pthread_mutex_lock(&philo->nb_eat_mtx);
	nb_eat = philo->nb_eat;
	pthread_mutex_unlock(&philo->nb_eat_mtx);
	return (nb_eat);
}

/*
	Incrase the number of times a philosopher has eaten
*/
void	philo_increase_nb_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->nb_eat_mtx);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->nb_eat_mtx);
}
