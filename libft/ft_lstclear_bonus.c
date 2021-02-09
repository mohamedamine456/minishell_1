/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:25:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:25:34 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ls1;
	t_list *ls2;

	ls1 = *lst;
	if (ls1 != NULL)
		while (ls1 != NULL)
		{
			ls2 = ls1->next;
			del(ls1->content);
			free(ls1);
			ls1 = ls2;
		}
	*lst = NULL;
}
