/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include <stdio.h>
# include <stdlib.h>

// minimal color codes
# define TNRM  "\x1B[0m"
# define TRED  "\x1B[31m"
# define TGRN  "\x1B[32m"
# define TYEL  "\x1B[33m"
# define TBLU  "\x1B[34m"
# define TMAG  "\x1B[35m"
# define TCYN  "\x1B[36m"
# define TWHT  "\x1B[37m"

// unit test type
typedef struct s_test {
	int		type;
	int		nb_tests;
	int		nb_success;
	int		nb_errors;
}	t_test;

// testing functions
void	test_init_struct(t_test *test);
void	test_show_start(t_test *test);
void	test_show_result(t_test *test);

// unit testing functions
void	utest(int is_error, char *s, t_test *test);

#endif