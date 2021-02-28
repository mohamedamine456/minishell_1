/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:53:33 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:28:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		fatal(char *error)
{
	char	*error_message;

	error_message = malloc(ft_strlen(error) + 19);
	ft_strlcpy(error_message, "[!!] Fatal Error: ", 19);
	ft_strlcat(error_message + 18, error, ft_strlen(error));
	write(1, error_message, ft_strlen(error_message));
	free(error_message);
	exit(-1);
}

void		*ec_malloc(unsigned int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in ec_malloc() on memory allocation.");
	return (ptr);
}
