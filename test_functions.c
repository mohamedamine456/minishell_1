# include "minishell.h"

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

void		print_commands(char **tab)
{
	int		i;

	i = 0;
	{
		while (tab[i] != NULL)
		{
			write(1, ">>>>> command <<<<<\n", 21);
			write(1, tab[i], ft_strlen(tab[i]));
			write(1, "\n>>>>> end <<<<<", 17);
			write(1, "\n", 1);
			i++;
		}	
	}
}