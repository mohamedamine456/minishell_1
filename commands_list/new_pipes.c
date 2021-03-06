# include "lists.h"

t_pipes		*new_pipe()
{
	t_pipes		*pipe;

	pipe = (t_pipes *)malloc(sizeof(t_pipes));
	pipe->name = NULL;
	pipe->options = NULL;
	pipe->args = NULL;
	pipe->redirect = NULL;
	pipe->next = NULL;
	return (pipe);
}