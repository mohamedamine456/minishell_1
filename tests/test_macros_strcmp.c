#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define ECHO "echo env export"
# define tab "echo hello world"
#define SPACE 32

int		compare(char *str)
{
	if (str == ECHO)
		return (1);
	return (0);
}

int main()
{
	char space;
	char *str = "echo";
	space = (char)32;
	/*if (space == SPACE)
		printf("space");
	if (compare(str))
		printf("echo");*/
	printf("%s", tab);
	return (0);
}
