# include "../libft/libft.h"
# include "../parsing_cleaning/parsing_cleaning.h"
# include "../check_functions/check_functions.h"
# include <stdio.h>

int main(int argv, char **argc, char **envp)
{
	char *str;
	str = replace_str(ft_strdup("LESS"), envp);
	printf("%s\n", str);
	//free(str);
	while (1)
	{
		continue ;
	}	
	return (0);
}
