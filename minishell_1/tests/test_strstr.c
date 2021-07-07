# include <stdio.h>
# include "../libft/libft.h"

int main()
{
	char *str1, *str2, *str3;
	int	index;

	str1 = ft_strdup("< file7 > file8 echo hello > file > file1 > file 2 < file5 < file6 > file9");
	str2 = ft_strdup("< file5");

	index = ft_strstri(str1, str2);
	printf("First index of [ %s ] in [ %s ] is: [ %d ]", str2, str1, index);
	return (0);
}