# include "lists.h"

int     size_commands(t_commands *commands)
{
    int     i;

    i = 0;
    while (commands != NULL)
    {
        i++;
        commands = commands->next;
    }
    return(i);
}