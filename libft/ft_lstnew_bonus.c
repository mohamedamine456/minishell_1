/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:26:22 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:26:23 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lst_new;

	lst_new = malloc(sizeof(t_list));
	if (lst_new == NULL)
		return (NULL);
	lst_new->content = content;
	lst_new->next = NULL;
	return (lst_new);
}
