#include "lists.h"

void        addfront_command(t_commands **commands, t_commands *new)
{
    if (new != NULL)
    {
        new->next = *commands;
        *commands = new;
    }
}