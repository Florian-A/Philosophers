/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_list	*ft_lstfirst(t_list *lst)
{
	int		i;
	t_list	*lst1;

	if (lst != NULL)
	{
		i = 1;
		lst1 = lst;
		while (lst1->previous != NULL)
		{
			lst1 = lst1->previous;
			i++;
		}
		return (lst1);
	}
	else
		return (0);
}
