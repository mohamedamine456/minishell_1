#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define ECHO "echo"
#define SPACE 32
int main()
{
	char space;
	char *str = strdup("echo");
	space = (char)32;
	if (space == SPACE)
		printf("space");
	if (str == ECHO)
		printf("echo");
	return (0);
}
