#include "../parsing_cleaning/parsing_cleaning.h"
#include <stdio.h>
#include "../libft/libft.h"

typedef enum
{
	oper1,
	oper2,
	oper3
}               operations;

typedef struct  s_enum_word
{
	operations  operation;
	char        *operation_name;
}				t_enum_word;

operations  word_enum(char *word)
{
	t_enum_word functions[] = {
		{oper1, "special_char"},
		{oper2, "alpha_char"},
		{oper3, "digit_char"}
	};
	int     i = 0;

	while (i < 4)
	{
		if (!ft_strcmp(functions[i].operation_name, word))
			return (functions[i].operation);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*str;

	char *(*func[])(char *, int *) = {special_char, alpha_char, digit_char};
	str = func[word_enum("alpha_char")]("Hello", 0);
	printf("%s\n", str);
}
