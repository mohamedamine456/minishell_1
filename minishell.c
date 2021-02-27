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

// int		read_command_line(char **command_line)
// {
// 	char	*buffer;

// 	if (get_next_line(1, &buffer))
// 	{
// 		*command_line = ft_strjoin(*command_line, buffer);
// 		return (1);
// 	}
// 	return (0);
// }

void		parse_command_line(char	*command_line, int nb_command)
{
	write(1, "\n-------------- command number: ", 33);
	ft_putnbr(nb_command);
	write(1, " ---------------\n", 18);
	write(1, command_line, ft_strlen(command_line));
	write(1, "\n-------------------------------------------------\n", 52);
}

int main()
{
	char	*command_line;
	int		nb_command;

	nb_command = 0;
	command_line = ft_strdup("");
	while (TRUE)
	{
		write(1, "MiniShell $> ", 13);
		if (get_next_line(1, &command_line))
		{
			parse_command_line(command_line, nb_command);
			nb_command++;
			write(1, "\n", 1);
		}
	}
}