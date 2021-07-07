# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	sleep (12);
	close(fd);
}
