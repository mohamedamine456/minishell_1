# include "lists.h"

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