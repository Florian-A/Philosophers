/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

void	test_block1(t_test *test)
{
	utest(test_create_philo(), "create_philo", test);
	utest(test_get_left_philo(), "get_left_philo", test);
	utest(test_ms_betwen(), "ms_betwen", test);
	utest(test_ms_sleep(), "ms_sleep", test);
	utest(test_ms_from_last_eat(), "ms_from_last_eat", test);
	utest(test_ms_from_start(), "ms_from_start", test);
}

int	main(int argc, char **argv, char **env)
{
	t_test	test;

	(void)argc;
	(void)argv;
	(void)env;
	test.type = 1;
	test_init_struct(&test);
	test_show_start(&test);
	test_block1(&test);
	test_show_result(&test);
}
