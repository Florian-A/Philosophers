/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	utest(int is_error, char *s, t_test *test)
{
	test->nb_tests++;
	if (is_error == -1)
	{
		printf("%s %s[FAIL]%s \n", s, TRED, TNRM);
		test->nb_errors++;
	}
	else
	{
		printf("%s %s[SUCCESS]%s \n", s, TGRN, TNRM);
		test->nb_success++;
	}
}
