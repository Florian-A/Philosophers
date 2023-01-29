/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_betwen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	test_ms_betwen_a(void)
{
	long long	t1;
	long long	t2;
	long long	t3;

	t1 = ms_timestamp();
	usleep(5000);
	t2 = ms_timestamp();
	t3 = ms_betwen(t1, t2);
	if (t3 > 0 && t3 < 20)
		return (0);
	return (-1);
}

int	test_ms_betwen(void)
{
	if (test_ms_betwen_a() == -1)
		return (-1);
	return (0);
}
