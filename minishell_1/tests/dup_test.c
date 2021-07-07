#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#define FILE_NAME "test.txt"

int main()
{
	int fd;
	int	tmpfd;

	fd = open(FILE_NAME, O_CREAT | O_APPEND | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
		perror("fd error()");
	tmpfd = dup(fd);
	if (tmpfd == -1 && errno != EBADF)
		perror("dup error()");
	else
	{
		printf("fd: %d\ttmpfd: %d\n", fd, tmpfd);
		write(tmpfd, "This will be output to the file named test.txt\n", 47);
		write(fd, "This will also be output to the file named test.txt\n", 52);
	}
	return (0);
}
