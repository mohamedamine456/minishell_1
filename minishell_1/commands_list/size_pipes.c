# include "lists.h"

/**
 * This Funtion count the size of t_pipes list given
*/

int		size_pipes(t_pipes *pipes)
{
	int		i;

	i = 0;
	while (pipes != NULL)
	{
		i++;
		pipes = pipes->next;
	}
	return (i);
}