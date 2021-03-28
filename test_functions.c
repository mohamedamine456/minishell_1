# include "minishell.h"

/**
 * All functions here just for test i use them to print results 
*/

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
			printf("Command %d : [%s]\n", i + 1, tab[i]);
			// write(1, "\n>>>>> command <<<<<\n", 21);
			// write(1, tab[i], ft_strlen(tab[i]));
			// write(1, "\n>>>>>>> end <<<<<<<", 21);
			// write(1, "\n", 1);
			i++;
		}	
	}
}

void	print_args(char **args)
{
	int	i = 0;

	while (args[i] != NULL)
	{
		printf("|%s| - ", args[i]);
		i++;
	}
}

void	print_command_parts(t_commands *command)
{
	int	i = 0;
	t_pipes *pip;

	pip = NULL;
	while (command != NULL)
	{
		printf("Command N %d : [[ ", i + 1);
		if (command->name != NULL)
			printf("Name : |%s| * ", command->name);
		if (command->options != NULL)
			printf("Options : |%s| * ", command->options);
		else
			printf("No options * ");
		if (command->arguments != NULL)
		{
			printf("\n\t\t{ Arguments :  ");
			print_args(command->arguments);
			printf(" } ");
		}
		if (command->redirect != NULL)
			print_redirections(command->redirect);
		if (command->input != NULL)
			print_inputs(command->input);
		pip = command->piped;
		while (pip != NULL)
		{
			printf("\n\t\t{ Pipe : ");
			if (pip->name != NULL)
				printf("Name : |%s| * ", pip->name);
			if (pip->options != NULL)
				printf("Options : |%s| * ", pip->options);
			if (pip->args != NULL)
			{
				printf("Arguments: (");
				print_args(pip->args);
				printf(" ) ");
			}
			if (pip->redirect != NULL)
				print_redirections(pip->redirect);
			if (pip->input != NULL)
				print_inputs(pip->input);
			printf(" } ");
			pip = pip->next;
		}
		printf(" ]]\n");
		command = command->next;
		i++;
	}
}


void	print_redirections(char **tab_redir)
{
	int i;

	i = 0;
	printf("\n\t\t{ Redirections : ");
	if (tab_redir == NULL)
		printf("No Redirections.");
	else
	{
		while (tab_redir[i] != NULL)
		{
			printf(" |%s| - ", tab_redir[i]);
			i++;
		}
	}
	printf(" }");
}

void	print_inputs(char **tab_input)
{
	int i;

	i = 0;
	printf("\n\t\t{ Inputs : ");
	if (tab_input == NULL)
		printf("No Redirections.");
	else
	{
		while (tab_input[i] != NULL)
		{
			printf(" |%s| - ", tab_input[i]);
			i++;
		}
	}
	printf(" }");
}
