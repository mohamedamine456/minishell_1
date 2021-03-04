#ifndef STRUCTS_H
# define STRUCTS_H
# include <sys/types.h>

/*
*
*/

typedef struct			s_commands
{
	int					command_id;
	char				*name;
	char				*options;
	char				**arguments;
	int					id_command_pipe;
	char				*redirect;
	struct s_commands	*next;
}						t_commands;

/*
*
*/

typedef struct			s_flags
{
	int		p_v : 1;
	int		d_q : 1;
	int		s_q : 1;
	int		p_l : 1;
}						t_flags;

#endif
