# include "lists.h"

t_pipes		*last_pipe(t_pipes *pipes)
{
	if (pipes != NULL)
	{
		while (pipes->next != NULL)
		{
			pipes = pipes->next;
		}
	}
	return (pipes);
}