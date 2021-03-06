#include "lists.h"

void			addfront_pipes(t_pipes **pipes, t_pipes *new)
{
	if (new != NULL)
	{
		new->next = *pipes;
		*pipes = new;
	}
}