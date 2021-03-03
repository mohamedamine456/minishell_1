#ifndef STRUCT_H
# define STRUCT_H
# include <sys/types.h>

typedef struct  s_commands
{
    int     command_id;
    char    *name;
    char    *options;
    char    **arguments;
    int     id_command_pipe;
    char    *redirect;
}               t_commands;

#endif