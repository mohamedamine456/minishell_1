#include "lists.h"

/**
 * This Funtion clear t_commands list from all items
*/

void        clear_commands(t_commands **commands)
{
    t_commands *cmd1;
    t_commands *cmd2;

    cmd1 = *commands;
    while (cmd1 != NULL)
    {
        cmd2 = cmd1->next;
        if (cmd1->name != NULL)
            free(cmd1->name);
        if (cmd1->options != NULL)
            free(cmd1->options);
        if (cmd1->arguments != NULL)
            ft_free_args(cmd1->arguments);
        if (cmd1->piped != NULL)
            clear_pipes(&(cmd1->piped));
        if (cmd1->redirect != NULL)
            ft_free_args(cmd1->redirect);
        if (cmd1->input != NULL)
            ft_free_args(cmd1->input);
        free(cmd1);
        cmd1 = NULL;
        cmd1 = cmd2;
    }
    commands = NULL;
}