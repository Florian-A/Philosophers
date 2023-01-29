/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;
	size_t	len;

	len = count * size;
	pnt = malloc(len);
	if (!pnt)
		return (NULL);
	ft_memset(pnt, 0, len);
	return (pnt);
}
