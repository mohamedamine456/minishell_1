#include "lists.h"

void	clear_pipes(t_pipes **pipes)
{
	t_pipes	*pipe1;
	t_pipes	*pipe2;

	pipe1 = *pipes;
	while (pipe1 != NULL)
	{
		pipe2 = pipe1->next;
		if (pipe1->name != NULL)
			free(pipe1->name);
		if (pipe1->options != NULL)
			free(pipe1->options);
		if (pipe1->args != NULL)
			ft_free_args(pipe1->args);
		if (pipe1->redirect != NULL)
			free(pipe1->redirect);
		free(pipe1);
		pipe1 = NULL;
		pipe1 = pipe2;
	}
	pipes = NULL;
}