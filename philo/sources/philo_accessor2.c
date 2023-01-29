/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_accessor2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	Set ID of philosopher who took the fork
*/
int	philo_get_fork_taken_by(t_philo *philo)
{
	int	philo_id;

	pthread_mutex_lock(&philo->fork_taken_by_mtx);
	philo_id = philo->fork_taken_by;
	pthread_mutex_unlock(&philo->fork_taken_by_mtx);
	return (philo_id);
}

/*
	Get ID of philosopher who took the fork
*/
void	philo_set_fork_taken_by(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->fork_taken_by_mtx);
	philo->fork_taken_by = philo_id;
	pthread_mutex_unlock(&philo->fork_taken_by_mtx);
}
