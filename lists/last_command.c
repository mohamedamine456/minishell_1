# include "lists.h"

t_commands  *last_command(t_commands *commands)
{
    if (commands != NULL)
    {
        while (commands->next != NULL)
        {
            commands = commands->next;
        }
    }
    return (commands);
}