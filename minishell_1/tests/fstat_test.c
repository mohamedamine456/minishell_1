#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int		main()
{
  char fn[]="temp.file";
  struct stat info;
  int fd;

  if ((fd = open(fn, O_CREAT | O_APPEND | O_RDWR, S_IRUSR | S_IWUSR)) < 0)
    perror("creat() error");
  else {
    if (fstat(fd, &info) != 0)
      perror("fstat() error");
    else {
      puts("fstat() returned:");
      printf("  inode:   %d\n", (int) info.st_ino);
      printf(" dev id:   %d\n", (int) info.st_dev);
      printf("   mode:   %08x\n", info.st_mode);
      printf("  links:   %d\n", info.st_nlink);
      printf("    uid:   %d\n", (int) info.st_uid);
      printf("    gid:   %d\n", (int) info.st_gid);
      //time also in the struct
    }
    close(fd);
  }
}
