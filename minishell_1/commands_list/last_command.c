# include "lists.h"

/**
 * This Funtion returns the last elemt from t_commands list given
*/

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