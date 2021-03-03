#include "lists.h"

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