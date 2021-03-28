#include <stdio.h>
#include <unistd.h>
#define ECHO "echo"
#define SPACE 32
int main()
{
	char space;
	char *str = "echo";
	//space = (char)32;
	//if (space == SPACE)
	//	printf("valide");
	if (str == ECHO)
		printf("Valide");
	return (0);
}
