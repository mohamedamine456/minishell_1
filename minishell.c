/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:05 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/03 09:21:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int main(int argc, char **argv, char **env)
{
	char	*command_line;

	while (TRUE)
	{
		write(1, "Minishell $> ", 13);
		if (get_next_line(0, &command_line) > 0)
		{
			write(1, command_line, ft_strlen(command_line));
			write(1, "\n", 1);
		}
	}
}