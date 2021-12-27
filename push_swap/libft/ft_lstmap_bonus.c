/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:48:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/27 10:46:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free_all(t_list *start);

t_list	*ft_lstmap(t_list *lst, t_list *lst_start, int(*f)(t_list*, int))
{
	t_list	*aux;
	t_list	*start;

	if (lst == NULL)
		return (0);
	aux = ft_lstnew(f(lst_start, lst->content));
	if (aux == NULL)
		return (0);
	start = aux;
	while (lst != NULL)
	{
		lst = lst->next;
		if (lst != NULL)
		{
			aux->next = ft_lstnew(f(lst_start, lst->content));
			aux->next->prev = aux;
			aux = aux->next;
		}
		if (aux == NULL)
		{
			ft_free_all(start);
			return (0);
		}
	}
	return (start);
}

static	void	ft_free_all(t_list *start)
{
	t_list	*aux;

	while (start != NULL)
	{
		aux = start;
		start = start->next;
		free(aux);
	}
	free(start);
}
