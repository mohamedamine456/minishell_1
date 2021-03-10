#include "lists.h"

/**
 * This Funtion create a new element of t_commands type
*/

t_commands      *new_command()
{
    t_commands *command;

    command = (t_commands *)malloc(sizeof(t_commands));
    command->name = NULL;
    command->options = NULL;
    command->arguments = NULL;
    command->piped = NULL;      // allocat it
    command->redirect = NULL;
    command->input = NULL;
    command->next = NULL;
    return (command);
}