# include "lists.h"

/**
 * This Funtion returns the last elemt from t_pipes list given
*/

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