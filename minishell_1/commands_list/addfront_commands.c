#include "lists.h"

/**
 * This Funtion add new element to the front of t_commands list
*/

void        addfront_command(t_commands **commands, t_commands *new)
{
    if (new != NULL)
    {
        new->next = *commands;
        *commands = new;
    }
}