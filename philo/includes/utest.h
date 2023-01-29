/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
# define UTEST_H

# include "../libtest/includes/libtest.h"
# include "./philosophers.h"

int		test_create_philo(void);
int		test_get_left_philo(void);
int		test_ms_betwen(void);
int		test_ms_from_last_eat(void);
int		test_ms_from_start(void);
int		test_ms_sleep(void);

#endif