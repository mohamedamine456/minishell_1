#include "lists.h"

/**
 * This Funtion add new element to the front of t_commands list
*/

void			addfront_pipes(t_pipes **pipes, t_pipes *new)
{
	if (new != NULL)
	{
		new->next = *pipes;
		*pipes = new;
	}
}