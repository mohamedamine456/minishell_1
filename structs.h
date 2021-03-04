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
	int		p_v;
	int		d_q;
	int		s_q;
	int		p_l;
}						t_flags;

#endif
