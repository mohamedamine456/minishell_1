#include "lists.h"

/**
 * This Funtion add new element to the end of t_commands list
*/

void        addback_commands(t_commands **commands, t_commands *new)
{
    t_commands *command;

    command = *commands;
    if (*commands == NULL)
        *commands = new;
    else
    {
        command = last_command(*commands);
        command->next = new;
    }
}