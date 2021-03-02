/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:05 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/02 17:59:58 by mlachheb         ###   ########.fr       */
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

int			check_line_errors(char *command)
{
	int		quotes;
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	quotes = 0;
	while (command[i] != '\0')
	{
		if (command[i] == '\'')
			quote++;
		if (command[i] == '\"')
			quotes++;
		i++;
	}
	if (quotes % 2 != 0 || quote % 2 != 0)
		return (0);
	return (1);
}

int		parse_command_line(char	*command_line)
{
	char	**table;
	int		i;

	i = 0;
	if (!check_line_errors(command_line))
	{
		write(1, "\nError:\nUndefined Behavior\n", 28);
		return (0);
	}
	else
	{
		table = ft_split(command_line, ' ');
		while (table[i] != NULL)
		{
			write(1, "---|", 4);
			write(1, table[i], ft_strlen(table[i]));
			write(1, "|---", 4);
			i++;
		}
		return (1);
	}
	// write(1, "\n-------------- command number: ", 33);
	// ft_putnbr(nb_command);
	// write(1, " ---------------\n", 18);
	// write(1, command_line, ft_strlen(command_line));
	// write(1, "\n-------------------------------------------------\n", 52);
}

void		print_env_variables(char **env)
{
	int		i;

	i = 0;
	{
		while (env[i] != NULL)
		{
			write(1, env[i], ft_strlen(env[i]));
			write(1, "\n", 1);
			i++;
		}	
	}
}

int main(int argc, char **argv, char **env)
{
	char	*command_line;

	//command_line = ft_strdup("");
	if (argc > 1)
	{
		fatal("This Shell requires no Arguments!!");
	}
	if (env == NULL)
	{
		fatal("Environment Variable!!");
	}
	//else
	//	print_env_variables(env);
	while (TRUE)
	{
		write(1, "Minishell $> ", 13);
		if (get_next_line(0, &command_line) > 0)
		{
			write(1, command_line, ft_strlen(command_line));
			//pr = parse_command_line(command_line);
			write(1, "\n", 1);
		}
	}
}
