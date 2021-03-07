# include "minishell.h"

void	put_elements_command(char **tab, t_commands **cmd)
{
	t_commands	*new_cmd;
	int			i;

	i = 1;
	new_cmd = new_command();
	if (tab[0] != NULL)
		put_simple_command(tab[0], &new_cmd);
	while (tab[i] != NULL)
	{
		put_pipes_to_command(tab[i], &new_cmd);
		i++;
	}
	addback_commands(cmd, new_cmd);
}

void	put_simple_command(char *simple_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;

	op = 0;
	tab = ft_split(simple_cmd, ' ');
	if (tab[0] != NULL)
		(*cmd)->name = ft_strdup(tab[0]);
	if (tab[1] != NULL && is_option(tab[1]))
	{
		(*cmd)->options = ft_strdup(tab[1]);
		op = 1;
	}
	else if(tab[1] != NULL && op == 0)
		put_args_to_command(cmd, tab + 1);
	else if (op == 1 && tab[2] != NULL)
		put_args_to_command(cmd, tab + 2);
	ft_free_args(tab);
}

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

void	put_pipes_to_command(char *pipe_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;
	t_pipes	*new;

	new = new_pipe();
	tab = ft_split(pipe_cmd, ' ');
	if (tab[0] != NULL)
		new->name = ft_strdup(tab[0]);
	if (tab[1] != NULL && is_option(tab[1]))
	{
		new->options = ft_strdup(tab[1]);
		op = 1;
	}
	else if (tab[1] != NULL && op == 0)
		put_args_to_pipe(&new, tab + 1);
	else if (tab[2] != NULL && op == 1)
		put_args_to_pipe(&new, tab + 2);
	addback_pipes(&((*cmd)->piped), new);
	ft_free_args(tab);
}

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