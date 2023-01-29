/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Message display
*/
#include "../includes/philosophers.h"

void	msg_log(t_cave *cave, int id, char *msg, long long timestamp)
{
	if (timestamp == 0)
		printf("%lld %d %s\n", ms_from_start(cave), id, msg);
	else
		printf("%lld %d %s\n", timestamp, id, msg);
}
