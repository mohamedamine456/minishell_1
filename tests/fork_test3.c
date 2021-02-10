#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	pid_t pid;

	//printf("%lu", sizeof(pid_t));
	pid = fork();
	if (pid == 0)
		printf("Hello from child\n");
	else
		printf("Hello from parent\n");
}
