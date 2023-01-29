/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_cave(t_cave *cave)
{
	cave->nb_philo = 0;
	cave->time_die = 0;
	cave->time_eat = 0;
	cave->time_sleep = 0;
	cave->min_eat = 0;
	cave->max_eat = 0;
	cave->start_timestamp = 0;
	cave->philo_lst = NULL;
	cave->exit = 0;
}

int	set_cave_param(t_cave *cave, char **argv)
{
	cave->nb_philo = ft_atoi(argv[1]);
	if (cave->nb_philo < 1)
		return (0);
	cave->time_die = ft_atoi(argv[2]);
	if (cave->time_die < 1)
		return (0);
	cave->time_eat = ft_atoi(argv[3]);
	if (cave->time_eat < 1)
		return (0);
	cave->time_sleep = ft_atoi(argv[4]);
	if (cave->time_sleep < 1)
		return (0);
	if (argv[5])
	{
		cave->max_eat = ft_atoi(argv[5]);
		if (cave->max_eat < 1)
			return (0);
	}
	cave->philo_lst = NULL;
	pthread_mutex_init(&cave->exit_mtx, NULL);
	pthread_mutex_init(&cave->min_eat_mtx, NULL);
	return (1);
}

int	fill_cave(t_cave *cave)
{
	int	i;

	i = 0;
	while (cave->nb_philo > i)
	{
		if (!create_philo(cave))
			return (0);
		i++;
	}
	return (1);
}
