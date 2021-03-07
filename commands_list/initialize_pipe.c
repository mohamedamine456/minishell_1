# include "lists.h"

t_pipes		*initialize_pipe(t_pipes *pipe)
{
	t_pipes *new;
	t_pipes *tmp;
	
	tmp = new;
	if (pipe != NULL)
	{
		tmp = (t_pipes *)malloc(sizeof(t_pipes));
		while (pipe != NULL)
		{
			tmp->name = ft_strdup(pipe->name);
			tmp->options = ft_strdup(pipe->options);
			tmp->args = ft_copy_args(pipe->args);
			tmp->redirect = ft_strdup(pipe->redirect);
			if (pipe->next == NULL)
				tmp->next = NULL;
			else
			{
				tmp->next = (t_pipes *)malloc(sizeof(t_pipes));
				tmp = tmp->next;
			}
			pipe = pipe->next;
		}
		return (new);
	}
	return ((t_pipes *)NULL);
}