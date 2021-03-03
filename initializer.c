# include "minishell.h"

void        initialize_commands(t_commands **commands)
{
    *commands = (t_commands *)malloc(sizeof(t_commands));
    (*commands)->name = NULL;
    (*commands)->options = NULL;
    (*commands)->arguments = NULL;
    (*commands)->id_command_pipe = 0;
    (*commands)->redirect = NULL;
    (*commands)->next = NULL;
}