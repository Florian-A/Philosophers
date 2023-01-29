/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	test_show_result(t_test *test)
{
	printf("_________________________________________\n\n");
	printf("> Total tests : %d\n", test->nb_tests);
	printf("%s> Success : %d%s\n", TGRN, test->nb_success, TNRM);
	printf("%s> Errors : %d%s\n", TRED, test->nb_errors, TNRM);
	printf("%s__________________________________________%s\n", TYEL, TNRM);
	if (test->nb_errors == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
