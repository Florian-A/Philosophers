/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	ms_timestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

long long	ms_betwen(long long t1, long long t2)
{
	return (t2 - t1);
}

long long	ms_from_last_eat(t_philo *philo)
{
	return (ms_betwen(philo->last_eat_timestamp, ms_timestamp()));
}

long long	ms_from_start(t_cave *cave)
{
	return (ms_betwen(cave->start_timestamp, ms_timestamp()));
}

void	ms_sleep(t_cave *cave, int time)
{
	long long	t1;
	long long	t2;

	t1 = ms_timestamp();
	if (time > cave->time_die)
	{
		usleep(cave->time_die * 1000);
		pthread_mutex_lock(&cave->exit_mtx);
		cave->exit = 1;
		pthread_mutex_unlock(&cave->exit_mtx);
		return ;
	}
	else
		usleep(0.90 * time * 1000);
	t2 = ms_timestamp();
	while (t2 < t1 + time)
	{
		usleep(100);
		t2 = ms_timestamp();
	}
}
