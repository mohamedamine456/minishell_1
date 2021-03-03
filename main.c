#include "minishell.h"



int main(int argc, char **argv, char **env)
{
	char	*command_line;

	if (argc == 1)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
                
                write(1, "\n", 1);
            }
        }
    }
}