/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:12:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/22 08:22:08 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
t_list	*ft_lst_top(t_list *lst)
{
	if (lst != 0)
	{
		while (lst->prev != 0)
		{
			lst = lst->prev;
		}
		return (lst);
	}
	return (0);
}