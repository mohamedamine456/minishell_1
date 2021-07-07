#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define FILE_NAME "test2.txt"

int main()
{
	int fd;

	fd = open(FILE_NAME, O_CREAT | O_APPEND | O_RDWR, S_IWUSR | S_IRUSR);
	// change the file descriptor of STDOUT to file test2.txt
	dup2(fd, 1);
	printf("This text will be printed at test2.txt");
	return (0);
}
