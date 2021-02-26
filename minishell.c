/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:05 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/11 10:05:37 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*command_line;
	char	*buffer;

	command_line = ft_strdup("");
	while (TRUE)
	{
		write(1, "MiniShell $> ", 13);
		if(get_next_line(1, &buffer) > 0)
		{
			command_line = ft_strjoin(command_line, buffer);
		}
		
	}
}
