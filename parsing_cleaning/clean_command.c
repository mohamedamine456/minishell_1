# include "parsing_cleaning.h"

void		clean_command(t_commands **new_cmd)
{
	t_pipes	*pip;

	if (*new_cmd != NULL)
	{
		if ((*new_cmd)->name != NULL)
			(*new_cmd)->name = clean_str((*new_cmd)->name);
		if ((*new_cmd)->options != NULL)
			(*new_cmd)->options = clean_str((*new_cmd)->options);
		if ((*new_cmd)->arguments != NULL)
			(*new_cmd)->arguments = clean_args((*new_cmd)->arguments);
		if ((*new_cmd)->input != NULL)
			(*new_cmd)->input = clean_args((*new_cmd)->input);
		if ((*new_cmd)->redirect != NULL)
			(*new_cmd)->redirect = clean_args((*new_cmd)->redirect);
		if ((*new_cmd)->piped != NULL)
		{
			pip = (*new_cmd)->piped;
			while (pip != NULL)
			{
				if (pip->name != NULL)
					pip->name = clean_str(pip->name);
				if (pip->options != NULL)
					pip->options = clean_str(pip->options);
				if (pip->args != NULL)
					pip->args = clean_args(pip->args);
				if (pip->redirect != NULL)
					pip->redirect = clean_args(pip->redirect);
				if (pip->input != NULL)
					pip->input = clean_args(pip->input);
				pip = pip->next;
			}
		}
	}
}

char		**clean_args(char **args)
{
	int i;

	i = 0;
	if (args == NULL)
		return (NULL);
	while (args[i] != NULL)
	{
		args[i] = clean_str(args[i]);
		i++;
	}
	return (args);
}
