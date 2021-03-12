# include "minishell.h"

/**
 * This function Takes parts of command and put them in the struct 
 * !!! still need some protection
*/

void	put_elements_command(char **tab, t_commands **cmd)
{
	t_commands	*new_cmd;
	int			i;

	i = 1;
	new_cmd = new_command();
	if (tab[0] != NULL)
	{
		split_redirections(ft_strdup(tab[0]), &new_cmd);
		tab[0] = remove_tab_from_string(tab[0], new_cmd->redirect);
		tab[0] = remove_tab_from_string(tab[0], new_cmd->input);
		put_simple_command(tab[0], &new_cmd);
		while (tab[i] != NULL)
		{
			put_pipes_to_command(ft_strdup(tab[i]), &new_cmd);
			i++;
		}
	}
	addback_commands(cmd, new_cmd);
}

/**
 * take the first part of the command and put it in the list 
*/

void	put_simple_command(char *simple_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;

	op = 0;
	tab = ft_split_white_spaces(simple_cmd);		// not the best split
	if (tab[0] != NULL)
	{
		(*cmd)->name = ft_strdup(tab[0]);
		if (tab[1] != NULL && is_option(tab[1], (*cmd)->name))
		{
			(*cmd)->options = ft_strdup(tab[1]);
			op = 1;
		}
		else if(tab[1] != NULL && op == 0)
			put_args_to_command(cmd, tab + 1);
		else if (op == 1 && tab[2] != NULL)
			put_args_to_command(cmd, tab + 2);
	}
	ft_free_args(tab);
}

/**
 * take table of strings and put it in the command list
*/

void	put_args_to_command(t_commands **cmd, char **args)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_args(args);
	(*cmd)->arguments = (char **)malloc(sizeof(char *) * (size + 1));
	while (args[i]!= NULL)
	{
		(*cmd)->arguments[i] = ft_strdup(args[i]);
		i++;
	}
	(*cmd)->arguments[i] = NULL;
}

/**
 * Take a pipe and put it into the list
*/

void	put_pipes_to_command(char *pipe_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;
	t_pipes *pip;

	op = 0;
	pip = new_pipe();
	split_pipes_redirections(ft_strdup(pipe_cmd), &pip);
	pipe_cmd = remove_tab_from_string(pipe_cmd, pip->redirect);
	pipe_cmd = remove_tab_from_string(pipe_cmd, pip->input);
	pipe_cmd = remove_spaces(pipe_cmd);
	tab = ft_split_white_spaces(pipe_cmd);			// not the best split
	if (tab[0] != NULL)
	{
		pip->name = ft_strdup(tab[0]);
		if (tab[1] != NULL && is_option(tab[1], (*cmd)->name))
		{
			pip->options = ft_strdup(tab[1]);
			op = 1;
		}
		else if (tab[1] != NULL && op == 0)
			put_args_to_pipe(&pip, tab + 1);
		else if (tab[2] != NULL && op == 1)
			put_args_to_pipe(&pip, tab + 2);
	}
	addback_pipes(&((*cmd)->piped), pip);
	ft_free_args(tab);
	free(pipe_cmd);
}

/**
 * take table of strings and put it in the pipe list
*/

void	put_args_to_pipe(t_pipes **pipe, char **args)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_args(args);
	(*pipe)->args = (char **)malloc(sizeof(char *) * (size + 1));
	while (args[i]!= NULL)
	{
		(*pipe)->args[i] = ft_strdup(args[i]);
		i++;
	}
	(*pipe)->args[i] = NULL;
}