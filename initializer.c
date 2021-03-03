# include "minishell.h"

t_commands      *initialize_commands()
{
    t_commands *command;

    command = (t_commands *)malloc(sizeof(t_commands));
    command->name = NULL;
    command->options = NULL;
    command->arguments = NULL;
    command->id_command_pipe = 0;
    command->redirect = NULL;
    command->next = NULL;
    return (command);
}