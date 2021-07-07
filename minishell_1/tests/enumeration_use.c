# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

enum	numbers
{
	number1 = 0,
	number2 = 1,
	number3 = 2,
	number4 = 3,
	number5 = 4
};

enum	numbers_default
{
	number_default1,
	number_default2,
	number_default3,
	number_default4,
	number_default5
};


int main()
{
	printf("number1 = %d, number2 = %d\n", number1, number2);
	printf("number1 = %d, number4 = %d\n", number_default1, number_default4);
	return  (0);
}
