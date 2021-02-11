#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int a = 7, b = 3;
	pid_t pid;

	//printf("%lu", sizeof(pid_t));
	pid = fork();
	if (pid == 0)
	{
		a = 8;
		b = 9;
		printf("Hello from child ==> a: %d, b: %d\n", a, b);
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("Hello from parent ==> a: %d, b: %d\n", a, b);
	}
}
