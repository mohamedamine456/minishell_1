#include "lists.h"

/**
 * This Funtion add new element to the end of t_pipes list
*/

void	addback_pipes(t_pipes **pipes, t_pipes *new)
{
	t_pipes	*pipe;

	pipe = *pipes;
	if (*pipes == NULL)
		*pipes = new;
	else
	{
		pipe = last_pipe(*pipes);
		pipe->next = new;
	}
}