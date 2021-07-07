# include "../test_functions.c"
# include <stdio.h>

int main(int argv, char **args, char **envp)
{
	print_env_variables(envp);
	return (0);
}
