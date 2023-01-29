/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	*1. Cave creation
	*2. Definition of the cave's parameters
	*3. Filling the cave with lot's of philosophers
	*4. Starting the routines
*/
int	main(int argc, char **argv, char **env)
{
	t_cave	cave;

	(void)env;
	init_cave(&cave);
	if (argc > 4 && argc < 7)
	{
		if (!set_cave_param(&cave, argv))
			return (error_exit(&cave, E_ARGS));
	}
	else
		return (error_exit(&cave, E_ARGS));
	if (!fill_cave(&cave))
		return (error_exit(&cave, E_ARGS));
	routine_cave(&cave);
	return (normal_exit(&cave));
}
