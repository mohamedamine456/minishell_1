#ifndef STRUCTS_H
# define STRUCTS_H
# include <sys/types.h>

/*
*
*/

typedef struct			s_pipes
{
	char				*name;
	char				*options;
	char				**args;
	struct s_pipes		*next;
}						t_pipes;

/*
*
*/

typedef struct			s_commands
{
	int					command_id;
	char				*name;
	char				*options;
	char				**arguments;
	t_pipes				*piped;
	char				*redirect;
	struct s_commands	*next;
}						t_commands;

/*
*
*/

typedef struct			s_flags
{
	int		p_v;		//comma
	int		d_q;		//doublequote
	int		s_q;		//singlequote
	int		p_l;		//pipeline
	int		b_s;		//backslash
	int		d_s;		//dollarsigne
}						t_flags;

#endif
